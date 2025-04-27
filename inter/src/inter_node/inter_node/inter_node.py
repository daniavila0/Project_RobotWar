import multiprocessing
import rclpy
from rclpy.node import Node

#multiprocessing.set_start_method('spawn')
# Esto es necesario porque con multiprocessing en fork no lo hace limpio el proceso
#y hereda lo del padre, lo que se ha hecho es pasar por estrin el nombre y dentro coger el proceso

import time
import numpy as np
import json
import copy

from coppeliasim_zmqremoteapi_client import RemoteAPIClient
client=RemoteAPIClient()
sim = client.require('sim')

from std_msgs.msg import String
#from std_msgs import Int32
from geometry_msgs.msg import Twist
#from geometry_msgs import Point
from sensor_msgs.msg import LaserScan
#from rosgame_msgs import rosgame_twist
#from rosgame_msgs import rosgame_point

colors={}
colors["Robot_1"]=[1,0,0]
colors["Robot_2"]=[0,1,0]
colors["Robot_3"]=[0,0,1]
colors["Robot_4"]=[1,0,1]
colors["Robot_5"]=[0,1,1]
laser_color=[1,0,0]

distance_between_wheels = 0.331 # meters
wheel_radius = 0.097518         # meters


class Broker (Node):
        
    def __init__(self,fovmat):
        super().__init__('my_broker')
        # Iniciar Simulación
        sim.startSimulation()
        # Publishers and Subscribers
        self.publisher_=self.create_publisher(String,'/scene_info',10)
        self.robot_gen= self.create_subscription(String,'/create_robot',self.callback_robot_gen,10)
        self.robot_gen
        # VARS
        self.n_robots=0
        self.handlers=[]
        self.sceneData = json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))#multiprocessing.Manager().dict()
        # Este loads va bien
        # Calculate FOV
        self.fovmat=fovmat
        self.timer = self.create_timer(5, self.calculateFOV)#Calcula la matriz de distancias 2 veces por segundo
        self.timerRead = self.create_timer(10,self.read_scene_data)
        self.processes=[]
        

    def callback_robot_gen(self,msg):
        self.get_logger().info('I heard: "%s"' % msg.data)
        #global sceneData
        self.n_robots +=1
        print("[robot_Generator] Creating a new robot. Robot number "+str(self.n_robots)+" named: "+ msg.data)
        file = '/home/daniel/Documentos/Project_ws/my_project/game_scene/model_robot.ttm'
        robot= sim.loadModel(file)
        self.handlers.append(robot)  # Pila de manejadores
        sim.setObjectAlias(robot,"Robot_"+str(self.n_robots))
        alias="Robot_"+str(self.n_robots)
        # params
        sim.setNamedBoolParam("hammer_enabled_"+alias,False)
        sim.setNamedBoolParam("shield_enabled_"+alias,False)
        #Tambien se crea un parametro para la recarga de bateria.
        sim.setNamedBoolParam("charger_enabled_"+alias,False)
        # Otro parametro adicional para el nivel de vida.
        sim.setNamedInt32Param("health_"+alias,100)
        #sim.setNamedStringParam("nick_Robot"+self.n_robots,msg.data)
        # poses
        def valid_pose(pos,poses_):
                for i in range(len(poses_)):
                    dist = np.linalg.norm(np.array(pos) - np.array(poses_[i][:2]))
                    if dist<2:
                        return False
                return True
        poses = self.get_all_positions()
        #print(f"[ DEBUG ] Estas son las poses iniciales: \n {poses}")
        p = sim.getObjectPosition(robot,-1)
        o = sim.getObjectOrientation(robot,-1)
        
        while (not valid_pose(p[:2],poses)):
                p[0]=np.random.rand()*10-5
                p[1]=np.random.rand()*10-5
                o[2]= o[2]+np.pi/2
        #p[2]= 0
        sim.setObjectPosition(robot,-1,p)
        sim.setObjectOrientation(robot,-1,o)
        self.sceneData["Robots"][alias]={"Battery": 100,"Pose":[p[0],p[1],o[2]]} 
                                         
        
        simple_scene_data = copy.deepcopy(self.sceneData)
        #print(simple_scene_data)
        sim.setBufferProperty(sim.handle_scene, "customData.myTag", json.dumps(simple_scene_data))

        # Es necesario tener el fov con nuestro robot antes de llamarlo, aparte del temporizador
        self.calculateFOV()

        #MULTIPROCESSING
        p=multiprocessing.Process(target=robot_thread,args=["Robot_"+str(self.n_robots),self.fovmat]) #argumento es el handler
        p.start()
        self.processes.append(p) #Crear una lista de procesos es importante
        
        
        
        #Leer datos
        #data = json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myScene"))
        #print(data["robots"])
        
    def get_all_positions(self):
        posiciones = []
        for categoria in ["Robots", "Chargers", "Skills", "Obstacles"]:
            for objeto in self.sceneData[categoria].values():
                if categoria == "Robots":
                    posiciones.append(objeto["Pose"][:2])
                else:
                    posiciones.append(objeto["Position"][:2])
        return posiciones
    
    def read_scene_data(self):
        self.sceneData = json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
        
    
    def calculateFOV(self): # Aqui no se si se estan actualizando
        if self.sceneData:
            scene_copy = copy.deepcopy(self.sceneData)
            #print(f"Este es el scene_copy:  {scene_copy}")
            #print(f"Este es el sceneData:  {self.sceneData}") # Funcionan ambos
            calc = multiprocessing.Process(target=Fov_array, args=(scene_copy,self.fovmat))
            calc.start()
            calc.join() # Es necesario esperar a que acabe el calculo, si no pueden cogerse valores erróneos
            #print(f"[ DEBUG ] Este es el fovmat de fuera, despues del join: \n{self.fovmat}")


def Fov_array(sceneData,fovmat):
    def get_positions(contenedor):
            elementos = contenedor.values() if isinstance(contenedor, dict) else contenedor
            return np.array([obj["Pose"][:2] if "Pose" in obj else obj["Position"][:2]for obj in elementos]) if elementos else np.empty((0, 2))           
         

    robots_pos = get_positions(sceneData["Robots"])
    chargers_pos = get_positions(sceneData["Chargers"])
    skills_pos = get_positions(sceneData["Skills"])
    obstacles_pos = get_positions(sceneData["Obstacles"])
    fovcopy={}
    for i, robot in enumerate(sceneData["Robots"]):
        alias = robot
        pos = robots_pos[i]
        fovcopy[alias]={}
        
        dist_robs=[]
        for j, other_pos in enumerate(robots_pos):
            if i == j:
                d = -1
            else:
                d = np.linalg.norm(pos - other_pos)
            dist_robs.append(d)
        fovcopy[alias]["robots"]= dist_robs
        for name, positions in [("chargers", chargers_pos), ("skills", skills_pos), ("obstacles", obstacles_pos)]:
            dist_list = []
            for obj_pos in positions:
                d = np.linalg.norm(pos - obj_pos)
                dist_list.append(d)
            fovcopy[alias][name] = dist_list
    fovmat.clear()
    fovmat.update(fovcopy)

    #print(f"[ DEBUG ] Este es el fovmat dentro : {fovmat}")




def robot_thread(name,fovmat):
    rclpy.init()
    class RobotNode(Node):
        def __init__(self,fovmat):
            super().__init__('robot_thread_node')
            self.handler=sim.getObject(f'/{name}')
            self.alias=sim.getObjectAlias(self.handler)
            self.sceneData=json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
            ### IMPORTANTE 
            # El fovmat del robot solo lee su parte
            self.fovmat = fovmat # debe de ser asi para que sea un diccionario compartido
            print(f"[ DEBUG ] Este el el fovmat de {self.alias}:\n {self.fovmat.get(self.alias,{})}")
            '''
            [ DEBUG ] Este el el fovmat de Robot_1:
            {'robots': [-1],
             'chargers': [4.062976385420454, 8.222223695267306, 3.524774232660133],
             'skills': [3.524774232660133, 3.524774232660133, 3.524774232660133, 3.524774232660133],
             'obstacles': [3.524774232660133, 3.524774232660133, 3.524774232660133, 3.524774232660133, 3.524774232660133]}

            '''
            # Se lee    self.fovmat.get(self.alias, {})
            # Publicadores y Subsciptores
            self.subscriber_vel = self.create_subscription(Twist,'/control_'+self.alias+'/cmdvel',self.cmd_callback,3)
            self.laser_publisher = self.create_publisher(LaserScan, f'/{self.alias}/laser_scan', 10)
            # Timer 
            self.timer = self.create_timer(5, self.thread)
            '''
            publicar scene
            refrescar scene
            sensing
            pub laser
            '''
            # Motores 
            self.motorLeft=sim.getObject(f"/{self.alias}/leftMotor")
            self.motorRight=sim.getObject(f"/{self.alias}/rightMotor")
            # Velocidades 
            self.v=0
            self.w=0
            '''
            #Color y Bounding Box
            self.color_id= sim.getObject(f"/{self.alias}/color_ID")
            sim.setObjectColor(self.color_id,0,sim.colorcomponent_ambient_diffuse,colors[self.alias])
            # Se define el area de colision del robot.
            self.collVolumeHandler = sim.getObject(f"/{self.alias}/coll")
            # Se define una "bounding box" alrededor del objeto que cubre el area necesaria para evitar colisiones.
            sim.setShapeBB(self.collVolumeHandler,{0.7,0.6,0.5})
            '''
            # Initialize Robot Parameters 
            self.ability_duration = 60    # seconds
            self.battery = 100            # initial battery level
            self.endgame = False
            self.health_level=sim.getNamedInt32Param("health_"+self.alias)
            # Hammer
            self.hammerEnabled = None
            self.hammerTimer_set = False
            sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Hammer"),sim.objintparam_visibility_layer,0)
            # Shield
            self.shieldEnabled = None
            self.shieldTimer_set = False
            sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Shield"),sim.objintparam_visibility_layer,0)
            # Fast Hokuyo
            self.selfsense=sim.getObject(f'/{self.alias}/fastHokuyo_ROS2')
            self.maxScanDistance=3
            self.measuredData=[]
            self.showLines=False
            self.generateData=True
            self.rangaData=True
            self.discardMaxDistPts= True
            self.visionSensors=[sim.getObject("./sensor1"),sim.getObject("./sensor2")]
    
            # La parte de colecciones no la entiendo bien
            '''
            local collection=sim.createCollection(0)
            sim.addItemToCollection(collection,sim.handle_all,-1,0)
            sim.addItemToCollection(collection,sim.handle_tree,self,1)
            self.shield=sim.getObject("../../Shield")
            sim.addItemToCollection(collection,sim.handle_single,shield,1)
  
            hammer=sim.getObject("../../Hammer")
            sim.addItemToCollection(collection,sim.handle_single,hammer,1)
            
            sim.setObjectInt32Param(self.visionSensors[1],sim.visionintparam_entity_to_render,collection)
            sim.setObjectInt32Param(self.visionSensors[2],sim.visionintparam_entity_to_render,collection)
            '''
            sim.setObjectFloatParam(self.visionSensors[0],sim.visionfloatparam_far_clipping,self.maxScanDistance)
            sim.setObjectFloatParam(self.visionSensors[1],sim.visionfloatparam_far_clipping,self.maxScanDistance)
            self.lines=sim.addDrawingObject(sim.drawing_lines,1,0,-1,1000,laser_color)

        def thread(self):
            self.read_scene_data()
            scene_copy = copy.deepcopy(self.sceneData)
            #node.get_logger().info(f'Funciona el cmd thread del {name}')
            '''           
            # Health Management
            self.health_level=sim.getNamedParam("health_"+self.alias)
            if self.health_level == 0.0:
                self.v=0
                self.w=0
                fire = sim.loadModel(sim.getStringParam(sim.stringparam_scene_path)+"/model_fire.ttm")
                p_robot = sim.getObjectPosition(self.handler,sim.handle_world)
                sim.setObjectPosition(fire,-1,p_robot)
                print("GAME OVER for "+self.alias)
                self.endgame = True
            # Refresh current position and health to scene Data
            p=sim.getObjectPosition(self.handler,sim.handle_world)
            o=sim.getObjectOrientation(self.handler,sim.handle_world)
            self.sceneData["Robots"][self.alias]["Pose"]=[p[0],p[1],o[2]]
            self.sceneData["Robots"][self.alias]["Health"]=self.health_level
            '''
            # ESTO SI LO SACO A UNA FUNCIÓN PUEDO CONTROLAR EL TIEMPO DE CARGA APARTE   
            # Battery management
            battery = self.sceneData["Robots"][self.alias]["Battery"]
            close2charger= False 
            for dist in self.fovmat.get(self.alias,{}).get("chargers") :
                if dist < 0.2:
                    close2charger=True 
                    break
            if close2charger and self.v==0:    # Cerca de un cargador y está parado
                battery = battery + 1 if battery < 100 else 100.0
            else:
                if (battery>0.0):
                    battery = battery - 0.01*(np.abs(self.v)+np.abs(self.w))
                    battery = 0.0 if battery<=0.0 else battery
            self.sceneData["Robots"][self.alias]["Battery"]= battery# despues hay que hacer un write

            if battery < 5:
                self.v=0.1*self.v
                self.w=0.1*self.w

            
            #print(f"v:{self.v},w:{self.w}")
            # cmd_vel to wheel speeds conversion
            if not(self.w==0):
                R=self.v/self.w
                vLeft= self.w*(R-distance_between_wheels/2)
                vRight=self.w*(R+distance_between_wheels/2)
            else:
                vLeft=self.v
                vRight=self.v
            vLeft= 0.0 if vLeft is None else vLeft
            vRight= 0.0 if vRight is None else vRight

            sim.setJointTargetVelocity(self.motorLeft,vLeft/wheel_radius)
            sim.setJointTargetVelocity(self.motorRight,vRight/wheel_radius)
            '''
            self.hammerEnabled = sim.getNamedBoolParam("hammer_enabled_"+self.alias)
            self.shieldEnabled = sim.getNamedBoolParam("shield_enabled_"+self.alias)
            currentTime=sim.getSimulationTime()

            # Shield
            if self.shieldEnabled:
                if not shieldTimer_set:
                    shield_startTime=sim.getSimulationTime()
                    shieldTimer_set=True
                    sim.setObjectInt32Param(sim.getObject("../Shield"),sim.objintparam_visibility_layer,1)
                else:
                    if (currentTime - shield_startTime > self.ability_duration):
                        sim.setNamedBoolParam("shield_enabled_"+self.alias,False)
                        sim.setObjectInt32Param(sim.getObject("../Shield"),sim.objintparam_visibility_layer,0)
                        shieldTimer_set = False                
            '''
            self.write_scene_data()

        def read_scene_data(self):
            self.sceneData=json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
        def write_scene_data(self):
            sim.setBufferProperty(sim.handle_scene, "customData.myTag", json.dumps(self.sceneData))
            
        def cmd_callback (self,msg):
            #node.get_logger().info(f'Funciona el cmd callback de {name}')
            '''
            sim.setNamedFloatParam('cmd_vel_v_'+self.alias,msg.linear.x)
            sim.setNamedFloataram('cmd_vel_w_'+self.alias,msg.angular.z)
            '''
            self.v=1
            self.w=1
            pass

        def sensing(self):
            sim.addDrawingObjectItem(self.lines,None)
            self.measuredData=[]
            for index,sensor in self.visionSensors:
                r,t,u=sim.readVisionSensor(sensor)
                if u and u[1]:
                    sensorM = sim.getObjectMattrix(sensor,sim.handle_world)
                    relRefM = sim.getObjectMatrix(self.selfsense,sim.handle_world)
                    sim.invertMatrix(relRefM)
                    relRefM=sim.multiplyMatrices(relRefM,sensorM)
                    p=[0,0,0]
                    p=sim.multiplyVector(sensorM,p) # OPERAR CON NUMPY
                    t=[p[0],p[1],p[2],0,0,0]
                    for j in range(u[1]-1):
                        for k in range(u[1]-1):
                            w = 2 + 4 * (j * int(u[1]) + k)
                            v = [u[w+1], u[w+2], u[w+3], u[w+4]]

                            if self.generateData:
                                if self.rangeData:
                                    # Aquí se puede aplicar ruido: gaussian(0, sigma)
                                    self.measuredData.append(v[3])  # sin ruido
                                else:
                                    if v[3] < self.maxScanDistance * 0.9999 or not self.discardMaxDistPts:
                                        p = sim.multiplyVector(relRefM, v)
                                        self.measuredData.extend([p[0], p[1], p[2]])

                            if self.showLines:
                                p = sim.multiplyVector(sensorM, v)
                                t[3], t[4], t[5] = p[0], p[1], p[2]
                                sim.addDrawingObjectItem(self.lines, t)
            pass        
        def pub_laser(self):
            if len(self.measuredData) > 0:
                msg = {
                    'header': {
                        'stamp': sim.getSimulationTime(), # estaba simROS2 en vez de sim
                        'frame_id': '/' + self.alias + '/laser_scan'
                    },
                    'angle_min': -120 * np.pi / 180,
                    'angle_max': 120 * np.pi / 180,
                    'angle_increment': (240 / 683) * np.pi / 180,
                    'time_increment': 0,
                    'scan_time': sim.getSimulationTimeStep(),
                    'range_min': 0.001,
                    'range_max': self.maxScanDistance,
                    'ranges': self.measuredData,
                    'intensities': []
                }
            self.laser_publisher.publish(msg)
            pass
    node = RobotNode(fovmat)
    node.get_logger().info(f'Estas lanzando el robot thread de {name}')
    while rclpy.ok():
        try:
            rclpy.spin(node)
        except KeyboardInterrupt:
            node.destroy_node()
    
    rclpy.shutdown() 
    '''
    try:
        
    except KeyboardInterrupt:
        pass
    finally:
        
'''



def main(args=None):
    multiprocessing.set_start_method('spawn')
    fovmat = multiprocessing.Manager().dict()
    rclpy.init(args=args)
    node = Broker(fovmat)
    while rclpy.ok():
        try:
            rclpy.spin(node)
        except KeyboardInterrupt:
            sim.stopSimulation()
    node.destroy_node()
    rclpy.shutdown()   
    
if __name__ == '__main__':
    main()