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
from std_msgs.msg import Header
#from rosgame_msgs import rosgame_twist
#from rosgame_msgs import rosgame_point

colors={}
colors["Robot_1"]=[1,0,0]
colors["Robot_2"]=[0,1,0]
colors["Robot_3"]=[0,0,1]
colors["Robot_4"]=[1,0,1]
colors["Robot_5"]=[0,1,1]
colors["Robot_6"]=[1,0,0]
laser_color=[1,0,0]

distance_between_wheels = 0.331 # meters
wheel_radius = 0.097518         # meters

verbose = False

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
        #self.handlers=[]

        self.sceneData = json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
        
        # Este loads va bien
        # Calculate FOV
        self.fovmat=fovmat
        self.timer = self.create_timer(0.3, self.calculateFOV)
        self.timerpub=self.create_timer(0.3,self.publish_scene_data)
        self.timerRead = self.create_timer(0.3,self.read_scene_data)
        self.processes=[]
        

    def callback_robot_gen(self,msg):
        self.get_logger().info('I heard: "%s"' % msg.data)
        #global sceneData
        self.n_robots +=1
        print("[robot_Generator] Creating a new robot. Robot number "+str(self.n_robots)+" named: "+ msg.data)
        file=sim.getStringParam(sim.stringparam_scene_path) + "/game_models/model_robot.ttm"
        robot= sim.loadModel(file)
        #self.handlers.append(robot)  # Pila de manejadores
        sim.setObjectAlias(robot,"Robot_"+str(self.n_robots))
        alias="Robot_"+str(self.n_robots)
        # poses

        poses = self.get_all_positions()
        if verbose:
            print(f"[ DEBUG ] Estas son las poses iniciales: \n {poses}") 
        p = sim.getObjectPosition(robot,-1)
        o = sim.getObjectOrientation(robot,-1)
        
        while (not self.valid_pose(p[:2],poses)):
                p[0]=np.random.rand()*12-6
                p[1]=np.random.rand()*12-6
                o[2]= o[2]+np.pi/2
        #p[2]= 0
        sim.setObjectPosition(robot,-1,p)
        sim.setObjectOrientation(robot,-1,o)
        self.sceneData["Robots"][alias]={"Nickname": str(msg.data),"Battery": 100,"Pose":[p[0],p[1],o[2]],"Health": 100,"Skill":{"Hammer":False,"Shield":False}} 
                                         
        '''
        {
        "Robots": {
            "Robot_1": {
            "Nickname": "nickname",
            "Battery": 100,
            "Pose": [x, y, o],
            "Health": 100,
            "Skill": {
                "Hammer": false,
                "Shield": false
            }
            },
            "Robot_2": {}
        },
        "Obstacles": {
            "obstacle_1": {
            "Pose": [x, y]
            },
            "obstacle_2": {}
        },
        "Chargers": {
            "charger_1": {
            "Pose": [x, y]
            },
            "charger_2": {}
        },
        "Skills": {
            "skill_1": {
            "Pose": [x, y],
            "Skill": "skill_name"
            },
            "skill_2": {}
        }
        }
        '''
        simple_scene_data = copy.deepcopy(self.sceneData)
        #print(simple_scene_data)


        sim.setBufferProperty(sim.handle_scene, "customData.myTag", json.dumps(simple_scene_data))



        # Es necesario tener el fov con nuestro robot antes de llamarlo, aparte del temporizador
        self.calculateFOV()

        #MULTIPROCESSING
        proc=multiprocessing.Process(target=robot_thread,args=["Robot_"+str(self.n_robots),self.fovmat]) #argumento es el handler
        proc.start()
        self.processes.append(proc) #Crear una lista de procesos es importante
        
        
        
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
    def valid_pose(self,pos,poses_):
            for i in range(len(poses_)):
                dist = np.linalg.norm(np.array(pos) - np.array(poses_[i][:2]))
                if dist<2:
                    return False
            return True
    def read_scene_data(self):
        self.sceneData = json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
        
    def publish_scene_data (self):
        msg = String()
        msg.data=json.dumps(self.sceneData)
        self.publisher_.publish(msg)
        
    def calculateFOV(self): # Aqui no se si se estan actualizando
        if self.sceneData:
            scene_copy = copy.deepcopy(self.sceneData)
            if verbose:
                print(f"Este es el sceneData:  {self.sceneData}")
            calc = multiprocessing.Process(target=Fov_array, args=(scene_copy,self.fovmat))
            calc.start()
            calc.join() # Es necesario esperar a que acabe el calculo, si no pueden cogerse valores erróneo
            if verbose:
                print(f"[ DEBUG ] Este es el fovmat de fuera, despues del join: \n{self.fovmat}")


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
    if verbose:
        print(f"[ DEBUG ] Este es el fovmat dentro : {fovmat}")

def list_to_matrix(m):
    """Convierte lista de 12 elementos (Coppelia) a matriz 4x4 numpy."""
    return np.array([
        [m[0], m[1], m[2], m[3]],
        [m[4], m[5], m[6], m[7]],
        [m[8], m[9], m[10], m[11]],
        [0.0, 0.0, 0.0, 1.0]
    ])

def matrix_to_list(m):
    """Convierte matriz 4x4 numpy a lista de 12 elementos (para Coppelia)."""
    return [
        m[0,0], m[0,1], m[0,2], m[0,3],
        m[1,0], m[1,1], m[1,2], m[1,3],
        m[2,0], m[2,1], m[2,2], m[2,3]
    ]

def invert_matrix(m):
    """Invierte matriz 4x4."""
    return np.linalg.inv(m)

def multiply_matrices(m1, m2):
    """Multiplica dos matrices 4x4."""
    return np.dot(m1, m2)

def multiply_vector(m, v):
    """Multiplica matriz 4x4 por vector 3D (añadiendo 1 al final)."""
    v_hom = np.array([v[0], v[1], v[2], 1.0])
    res = np.dot(m, v_hom)
    return res[:3]  # devolvemos sólo x, y, z


def robot_thread(name,fovmat):
    rclpy.init()
    class RobotNode(Node):
        def __init__(self,fovmat):
            super().__init__('robot_thread_node')
            self.handler=sim.getObject(f'/{name}')
            self.alias=sim.getObjectAlias(self.handler)
            self.sceneData=json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
            self.nickname = self.sceneData["Robots"][self.alias].get("Nickname")
            self.verbose=True
            ### IMPORTANTE 
            # El fovmat del robot solo lee su parte
            self.fovmat = fovmat # debe de ser asi para que sea un diccionario compartido
            if verbose:
                print(f"[ DEBUG ] Este el el fovmat inicial de {self.alias}:\n {self.fovmat.get(self.alias,{})}")
            '''
            [ DEBUG ] Este el el fovmat de Robot_1:
            {'robots': [
                            -1
                        ],
             'chargers': [
                            4.06,
                            8.22
                        ],
             'skills': [
                            5.46,
                            3.52
                        ],
             'obstacles': [
                            2.1,
                            5.6
                        ]
            }
            '''
            # Se lee    self.fovmat.get(self.alias, {})
            # Publicadores y Subsciptores
            self.subscriber_vel = self.create_subscription(Twist,'/control_'+self.alias+'/cmdvel',self.cmd_callback,3)
            self.laser_publisher = self.create_publisher(LaserScan, f'/sensor_{self.alias}/laser_scan', 10)
            # Timer 
            self.timerThread = self.create_timer(0.2, self.thread)
            self.timerSensing=self.create_timer(0.1,self.sensing)
            self.timerDebug=self.create_timer(10,self.debugging)
            '''
            sensing
            pub laser
            '''
            # Motores 
            self.motorLeft=sim.getObject(f"/{self.alias}/leftMotor")
            self.motorRight=sim.getObject(f"/{self.alias}/rightMotor")
            # Velocidades 
            self.v=0
            self.w=0
            
            #Color y Bounding Box
            self.color_id= sim.getObject(f"/{self.alias}/color_ID")
            sim.setObjectColor(self.color_id,0,sim.colorcomponent_ambient_diffuse,colors[self.alias])
            
            # Se define el area de colision del robot.
            self.collVolumeHandler = sim.getObject(f"/{self.alias}/coll")
            # Se define una "bounding box" alrededor del objeto que cubre el area necesaria para evitar colisiones.
            sim.setShapeBB(self.collVolumeHandler,{0.7,0.6,0.5})
            
            # Initialize Robot Parameters 
            self.ability_duration = 60    # seconds
            self.battery = 100            # initial battery level
            self.close2charger = False
            self.endgame = False
            self.health_level=sim.getNamedInt32Param("health_"+self.alias)
            # Hammer
            self.hammerEnabled = self.sceneData["Robots"][self.alias]["Skill"].get("Hammer")
            self.hammerStartTime = None
            self.hammerUsed = None
            self.close2oponent= False
            sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Hammer"),sim.objintparam_visibility_layer,0)
            # Shield
            self.shieldEnabled = self.sceneData["Robots"][self.alias]["Skill"].get("Shield")
            self.shieldStartTime= None
            sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Shield"),sim.objintparam_visibility_layer,0)
            # Fast Hokuyo
            self.selfsense=sim.getObject(f'/{self.alias}/fastHokuyo_ROS2')
            self.maxScanDistance=3
            self.measuredData=[]
            self.showLines=False
            self.generateData=True
            self.rangeData=True
            self.discardMaxDistPts= True
            self.visionSensors=[sim.getObject("./sensor1"),sim.getObject("./sensor2")]
    
            # Evitar que el laser colisione con el escudo o el martillo
            
            collection=sim.createCollection(0)
            sim.addItemToCollection(collection,sim.handle_all,-1,0)
            sim.addItemToCollection(collection,sim.handle_tree,self.selfsense,1)

            sim.addItemToCollection(collection,sim.handle_single,sim.getObject(f"/{self.alias}/Shield"),1) # Funciona

            sim.addItemToCollection(collection,sim.handle_single,sim.getObject(f"/{self.alias}/Hammer"),1)
            
            sim.setObjectInt32Param(self.visionSensors[0],sim.visionintparam_entity_to_render,collection)
            sim.setObjectInt32Param(self.visionSensors[1],sim.visionintparam_entity_to_render,collection)
            
            sim.setObjectFloatParam(self.visionSensors[0],sim.visionfloatparam_far_clipping,self.maxScanDistance)
            sim.setObjectFloatParam(self.visionSensors[1],sim.visionfloatparam_far_clipping,self.maxScanDistance)

            self.lines=sim.addDrawingObject(sim.drawing_lines,1,0,-1,1000,laser_color)

        def thread(self):
            if not self.endgame:
                self.read_scene_data()
                #node.get_logger().info(f'Funciona el cmd thread del {name}')

                # Actualiza posición

                p = sim.getObjectPosition(self.handler,-1)
                o = sim.getObjectOrientation(self.handler,-1)
                self.sceneData["Robots"][self.alias]["Pose"]=[p[0],p[1],o[2]]
                    

                # Battery management

                self.battery = self.sceneData["Robots"][self.alias]["Battery"]
                self.close2charger= False 
                for dist in self.fovmat.get(self.alias,{}).get("chargers") :
                    if dist < 0.2:
                        self.close2charger=True 
                        break
                if self.close2charger and self.v==0:    # Cerca de un cargador y está parado
                    self.battery = self.battery + 1 if (self.battery+1) < 100 else 100
                else:
                    if (self.battery>0.0):
                        self.battery = self.battery-0.00001- 0.01*(np.abs(self.v)+np.abs(self.w))
                        self.battery = 0.0 if self.battery<=0.0 else self.battery
                self.sceneData["Robots"][self.alias]["Battery"]= self.battery# despues hay que hacer un write

                if self.battery < 5:
                    self.v=0.1*self.v
                    self.w=0.1*self.w
                
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

                # Health management

                # puedo hacer que health este en self o que este en sceneData
                self.health_level=self.sceneData["Robots"][self.alias].get("Health")
                #self.health_level=0   Funciona
                
                if self.health_level <=0 and not self.endgame:
                    self.v=0
                    self.w=0
                    fire = sim.loadModel(sim.getStringParam(sim.stringparam_scene_path)+"/model_fire.ttm")
                    p_robot = sim.getObjectPosition(self.handler,sim.handle_world)
                    sim.setObjectPosition(fire,-1,p_robot)
                    print("GAME OVER for "+self.nickname)
                    self.endgame = True

                # Lectura Skills
                
                # Ver si tiene alguna cerca
                close2skill=False
                for index,skill_pos in enumerate(self.fovmat.get(self.alias,{}).get('skills')):
                    try: 
                        sim.getObject("/Scene/skill_"+str(index+1))
                    except Exception:
                        continue
                    if skill_pos < 0.5:
                        name = "skill_"+str(index+1)
                        close2skill=True
                        break
                # Identificar la skill
                if close2skill:
                    skill_data=self.sceneData["Skills"][name]
                    #if skill_data:
                    ability=self.sceneData["Skills"][name].get("ID")
                    # Eliminar bloque de habilidad 
                    del self.sceneData["Skills"][name]
                    sim.removeObject(sim.getObject("/Scene/"+name))

                    if ability=="Hammer":
                        self.hammerStartTime=sim.getSimulationTime()
                        self.hammerEnabled=True
                        self.hammerUsed = False
                        sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Hammer"),sim.objintparam_visibility_layer,1)
                        pass
                    elif ability=="Shield":
                        self.shieldStartTime=sim.getSimulationTime()
                        self.shieldEnabled=True
                        self.sceneData["Robots"][self.alias]["Skill"]["Shield"]=True
                        sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Shield"),sim.objintparam_visibility_layer,1)
                        pass
                    if self.verbose:
                        print(f"[ DEBUG ] Habilidad : {ability}")

                # Shield
                self.shieldEnabled=self.sceneData["Robots"][self.alias]["Skill"]["Shield"]
                if (self.shieldEnabled and (sim.getSimulationTime()-self.shieldStartTime)>self.ability_duration):
                    self.shieldEnabled=False
                    sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Shield"),sim.objintparam_visibility_layer,0)
                self.sceneData["Robots"][self.alias]["Skill"]["Shield"]= self.shieldEnabled
                
                # Hammer

                if self.hammerEnabled:
                    active_time = sim.getSimulationTime() - self.hammerStartTime
                    if not self.hammerUsed and active_time<self.ability_duration:
                        # Comprobar si robots cerca
                        self.close2oponent=False
                        for i,distance in enumerate(self.fovmat.get(self.alias,{}).get("robots")):
                            if distance > 0 and distance <0.8:
                                self.close2oponent=True
                                oponent= "Robot_"+str(i+1)
                                break
                        #print(f"Close to oponent: {self.close2oponent}\tdistances: {self.fovmat.get(self.alias,{}).get("robots")}")
                        # Comporbar si tiene escudo
                        if self.close2oponent:
                            oponentShield=self.sceneData["Robots"][oponent]["Skill"].get("Shield")
                            if oponentShield:
                                self.sceneData["Robots"][oponent]["Health"]-=20
                                self.sceneData["Robots"][oponent]["Skill"]["Shield"]= False
                            else:
                                self.sceneData["Robots"][oponent]["Health"]-=100
                            pass
                            self.hammerUsed=True
                            self.hammerEnabled=False
                            
                    if self.hammerUsed or active_time>=self.ability_duration:
                        self.hammerEnabled=False
                        sim.setObjectInt32Param(sim.getObject(f"/{self.alias}/Hammer"),sim.objintparam_visibility_layer,0)
                self.sceneData["Robots"][self.alias]["Skill"]["Hammer"]= self.hammerEnabled

                
                
                self.write_scene_data()


        def read_scene_data(self):
            self.sceneData=json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myTag"))
        def write_scene_data(self):
            sim.setBufferProperty(sim.handle_scene, "customData.myTag", json.dumps(self.sceneData))

        def debugging(self):
            if self.verbose:
                if not self.endgame:
                    self.get_logger().info(f"[{self.nickname}] Pose: {self.sceneData['Robots'][self.alias]['Pose']}")
                    self.get_logger().info(f"[{self.nickname}] Battery: {self.battery} | Cerca de cargador: {self.close2charger}")
                    self.get_logger().info(f"[{self.nickname}] Skill: {self.sceneData['Robots'][self.alias]['Skill']}")
                    self.get_logger().info(f"[{self.nickname}] v: {self.v}, w: {self.w}")
                    self.get_logger().info(f"[{self.nickname}] Health: {self.health_level}")
                else:
                    self.get_logger().info(f"[{self.nickname}] GAME OVER")
                    
        def cmd_callback (self,msg):
            self.v=msg.linear.x
            self.w=msg.angular.z
            pass

        def sensing(self):
            sim.addDrawingObjectItem(self.lines, None)
            self.measuredData = []

            for i in range(2):
                r, t, u = sim.readVisionSensor(self.visionSensors[i])

                if u:
                    sensorM_list = sim.getObjectMatrix(self.visionSensors[i], sim.handle_world)
                    relRefM_list = sim.getObjectMatrix(self.selfsense, sim.handle_world)

                    sensorM = list_to_matrix(sensorM_list)
                    relRefM = list_to_matrix(relRefM_list)

                    relRefM_inv = invert_matrix(relRefM)
                    relRefM_sensor = multiply_matrices(relRefM_inv, sensorM)

                    p = multiply_vector(sensorM, [0, 0, 0])
                    t = [p[0], p[1], p[2], 0, 0, 0]

                    u1 = int(u[0]) # dimension horizontal
                    u2 = int(u[1]) # dimension vertical

                    for j in range(u2):
                        for k in range(u1):
                            w = 2 + 4 * (j * u1 + k)
                            if w+3 < len(u): # Controlar que no se pase
                                v = [u[w], u[w+1], u[w+2], u[w+3]] # datos x y z dist

                                if self.generateData:
                                    if self.rangeData:
                                        self.measuredData.append(v[3])
                                    else:
                                        if v[3] < self.maxScanDistance * 0.9999 or not self.discardMaxDistPts:
                                            p_rel = multiply_vector(relRefM_sensor, v)
                                            self.measuredData.extend([p_rel[0], p_rel[1], p_rel[2]])

                                if self.showLines:
                                    p_sensor = multiply_vector(sensorM, v)
                                    t[3], t[4], t[5] = p_sensor[0], p_sensor[1], p_sensor[2]
                                    sim.addDrawingObjectItem(self.lines, t)
            self.pub_laser()

            pass        

        def pub_laser(self):
            if self.measuredData:
                scan_msg=LaserScan()
                scan_msg.header = Header()
                scan_msg.header.stamp = node.get_clock().now().to_msg()  
                scan_msg.header.frame_id = f"/{self.alias}/laser_scan"

                scan_msg.angle_min = -120 * np.pi / 180
                scan_msg.angle_max = 120 * np.pi / 180
                scan_msg.angle_increment = (240 / 683) * np.pi / 180  # 684 puntos totales

                scan_msg.time_increment = 0.0
                scan_msg.scan_time = sim.getSimulationTimeStep()
                scan_msg.range_min = 0.001
                scan_msg.range_max = float(self.maxScanDistance)

                # Asignar datos reales
                scan_msg.ranges = [float(r) for r in self.measuredData]
            if verbose:
                print(f"[ PUBLISH ] msg:{scan_msg}")
            self.laser_publisher.publish(scan_msg) # Funciona
            pass
    node = RobotNode(fovmat)
    node.get_logger().info(f'Estas lanzando el robot thread de {name}')
    while rclpy.ok():
        try:
            rclpy.spin(node)
        except KeyboardInterrupt:
            node.destroy_node()
    
    rclpy.shutdown() 




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