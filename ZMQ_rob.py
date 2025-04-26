from coppeliasim_zmqremoteapi_client import RemoteAPIClient
import multiprocessing
import time
import numpy as np

client = RemoteAPIClient()
sim = client.require('sim')
simROS2= client.require("simROS2")
simOMPL= client.require("simOMPL")

colors={}
colors["Robot1"]={1,0,0}
colors["Robot2"]={0,1,0}
colors["Robot3"]={0,0,1}
colors["Robot4"]={1,0,1}
colors["Robot5"]={0,1,1}


distance_between_wheels = 0.331 # meters
wheel_radius = 0.097518         # meters 

sim.startSimulation()
while (sim.getInt32Signal("Initialization")!=1):
    pass
# Recoger tabla de datos
dataRead()





def dataRead():
    _data=sim.readCustomDataBlock(sim.handle_scene, "customData.myTag", {'noError' : True})
    if _data:
        global sceneData
        sceneData=sim.unpackTable(_data)

        



# Creación de la tabla de datos de la escena visibles entre procesos
sceneData=multiprocessing.Manager().dict()
FOV_matrix=multiprocessing.Manager().dict()
# Hace falta saber como se obtienen el numero de robots
#procesos=6  Solo sirve para pool que no me conviene
n_skills=len(_data['skills'])
n_chargers=len(_data['chargers'])
n_obstacles=len(_data['obstacles'])
n_robots=len(_data['robots'])

robots=list(sceneData['robots'].keys())

# Matriz de control de distancias
FOV_matrix={'robots':np.zeros(len(robots),len(robots)),
            'chargers':np.zeros(len(robots),n_chargers),
            'skils':np.zeros(len(robots),n_skills),
            'obstacles':np.zeros(len(robots),n_obstacles)}
#sim.setStepping(True)
#sim.step()



def robot_thread(robot,robot_handler): #Esto esta en pañales
    global sceneData

    #robot_handler = sim.getObject(".")
    robotAlias=sim.getObjectAlias(robot_handler)

    if simROS2:
        subscriber_vel = simROS2.createSubscription('/control'+robotAlias+'/cmdvel','geometry_msgs/msg/Twist','cmd_callback')
        subscriber_pos = simROS2.createSubscription('/control'+robotAlias+'/goal_x_y','geomtry_msgs/msg/Point','cmd_pos_callback')
        publisher_scene = simROS2.createPublisher(robotAlias+'scene_info','std_msgs/msg/String')
    else:
        print("ERROR - simROS2 is not available")
    
    robotOrientation = sim.getObjectOrientation(robot_handler,-1)
    robotPosition = sim.getObjectPosition(robot_handler, sim.handle_world)
    sceneData['robots'][robot]['pose']= [robotPosition[0],robotPosition[1],robotOrientation]
    global FOV_matrix
    # Crear tabla para que puedan leer en coppelia
    sim.setBufferProperty(sim.handle_scene, "customData.myTag", sim.packTable(sceneData))

    # Actuation
    try:
        sdata=sim.getBufferProperty(sim.scene_handle,"customData.myTag", {'noError' : True})
        if sdata:
            sdata=sim.unpackTable(sdata)
            if int(time.time())%5==0:
                simROS2.publish(publisher_scene,sdata['robots'][robotAlias]) # Esto va a dar error        
    except Exception:
        sdata=sceneData
        print('Error de lectura')

    #Visible
    #init ########################## Esto va al generation
    #DEFINE ROBOT HANDLER
    motorLeft=sim.getObject("../leftMotor")
    motorRight=sim.getObject("../rightMotor")
    color_id= sim.getObject("../color_ID")
    color_id= sim.getObject("../color_ID")
    
    sim.setObjectColor(color_id,0,sim.colorcomponent_ambient_diffuse,colors[robotAlias])
    
    # Se define el area de colision del robot.
    collVolumeHandler = sim.getObject("../coll")
    # Se define una "bounding box" alrededor del objeto que cubre el area necesaria para evitar colisiones.
    sim.setShapeBB(collVolumeHandler,{0.7,0.6,0.5})


    # Se crea una coleccion con los obstaculos para evitar colisiones.
    robotObstaclesCollection = sim.createCollection(0)
    sim.addItemToCollection(robotObstaclesCollection,sim.handle_all,-1,0)
    sim.addItemToCollection(robotObstaclesCollection,sim.handle_tree,robot_handler,1)
    collPairs = {collVolumeHandler,robotObstaclesCollection}
    
    # Initialize Robot Parameters CAMBIAR ########################
    ability_duration = 60    # seconds
    battery = 100            # initial battery level
    endgame = False
    # Hammer
    hammerEnabled = None
    hammerTimer_set = False
    sim.setObjectInt32Param(sim.getObject("../Hammer"),sim.objintparam_visibility_layer,0)
    # Shield
    shieldEnabled = None
    shieldTimer_set = False
    sim.setObjectInt32Param(sim.getObject("../Shield"),sim.objintparam_visibility_layer,0)
   
    '''
    Voy por aqui
    '''
    
    # Thread
    while (not sim.getSimulationStopping() and not endgame):  #### Esto me hace que quite el main
        v = sim.getNamedFloatParam("cmd_vel_v_"+robotAlias)
        w = sim.getNamedFloatParam("cmd_vel_w_"+robotAlias)
        v = 0 if v is None else v
        w = 0 if w is None else w
        
        # Battery Managememt
        if sim.getNamedBoolParam("charger_enabled_"+robotAlias):
            battery = battery + 1 if battery < 100 else 100.0
        else:
            if (battery>0.0):
                battery = battery - 0.01*(np.abs(v)+np.abs(w))
                battery = 0.0 if battery<=0.0 else battery
        sim.setNamedBoolParam("battery_lvl_"+robotAlias)
        # sceneData["robots"]["RobotAlias"]["battery"]= battery
        # sim.setBuffer  #
        if battery < 0.1:
            v=0.1*v
            w=0.1*w
        

        # Health Management
        health_level=sim.getNamedParam("health_"+robotAlias)
        if health_level == 0.0:
            v=0.0
            w=0.0
            file = sim.getStringParam(sim.stringparam_scene_path)+"/model_fire.ttm"
            fire = sim.loadModel(file)
            p_robot = sim.getObjectPosition(robot_handler,sim.handle_world)
            sim.setObjectPosition(fire,-1,p_robot)
            print("GAME OVER for "+robotAlias)
            endgame = True
        
        # cmd_vel to wheel speeds conversion
        if not(w==0):
            R=v/w
            vLeft= w*(R-distance_between_wheels/2)
            vRight=w*(R+distance_between_wheels/2)
        else:
            vLeft=v
            vRight=v
        vLeft= 0.0 if vLeft is None else vLeft
        vRight= 0.0 if vRight is None else vRight

        sim.setJointTargetVelocity(motorLeft,vLeft/wheel_radius)
        sim.setJointTargetVelocity(motorRight,vRight/wheel_radius)
        

        # Abilities
        autopilotEnabled = sim.getNamedBoolParam("autopilot_enabled_"+robotAlias)
        hammerEnabled = sim.getNamedBoolParam("hammer_enabled_"+robotAlias)
        shieldEnabled = sim.getNamedBoolParam("shield_enabled_"+robotAlias)
        currentTime=sim.getSimulationTime()

        # Shield
        if shieldEnabled:
            if not shieldTimer_set:
                shield_startTime=sim.getSimulationTime()
                shieldTimer_set=True
                sim.setObjectInt32Param(sim.getObject("../Shield"),sim.objintparam_visibility_layer,1)
            else:
                if (currentTime - shield_startTime > ability_duration):
                    sim.setNamedBoolParam("shield_enabled_"+robotAlias,False)
                    sim.setObjectInt32Param(sim.getObject("../Shield"),sim.objintparam_visibility_layer,0)
                    shieldTimer_set = False
        # Hammer
        if hammerEnabled:
            if not hammerTimer_set:
                hammer_startTime=sim.getSimulationTime()
                hammerTimer_set=True
                hammer_used=False
                #Show Hammer over Robot
                sim.setObjectInt32Param(sim.getObject("../Hammer"),sim.objintparam_visibility_layer,1)
            else:
                if ((currentTime - hammer_startTime > ability_duration) or hammer_used):
                    sim.setNamedBoolParam("hammer_enabled_"+robotAlias,False)
                    hammerTimer_set = False
                    hammer_used = False
                    # Hide Hammer over Robot
                    sim.setObjectInt32Param(sim.getObject("../Hammer"),sim.objintparam_visibility_layer,0)
                else:
                    # We have a hammer ready to be used!
                    # check if any close robot to hit!
                    hierarchy = sim.getObject("/Robots_Generator")
                    robots_handlers = sim.getObjectsInTree(hierarchy, sim.handle_all, 3) # creo que no es necesario ###################
                    if (len(sceneData['robots']) > 0):################ Aqui he quitado los handlers pero en robot ge creo un array de handlers que es lo que me hace falta, lo meto de entrada o lo hago global
                        for i in sceneData['robots']:
                            # El robot actual no hay que tenerlo en cuenta.
                            if not (robotAlias==i):
                                # Se obtiene la posicion del jugador y se calcula la distancia al oponente.
                                #cga 
                                r,dist_Data,pair=sim.checkDistance(robot_handler,robots_handlers[i],0.15) # if distance is greater than 0.7 it returns 0
                                # p_oponent = sim.getObjectPosition(robots_handlers[i],sim.handle_world)
                                # p_robot = sim.getObjectPosition(robotHandler,sim.handle_world)
                                # distance = math.sqrt((p_robot[1]-p_oponent[1])^2 + (p_robot[2]-p_oponent[2])^2)
                                
                                if r==1:
                                    # Se comprueba si dicho oponente tiene activo el escudo.
                                    oponent_alias = sim.getObjectAlias(robots_handlers[i], -1)
                                    oponent_shield = sim.getNamedBoolParam("shield_enabled_"+oponent_alias)
                                    oponent_health = sim.getNamedInt32Param("health_"+oponent_alias)
                                    
                                    # Si el oponente no tiene escudo y aun no se le ha herido, disminuimos su vida.
                                    if not oponent_shield and not hammer_used:
                                        hammer_used = True
                                        oponent_health = oponent_health - 100
                                        sim.setNamedInt32Param("health_"+oponent_alias, oponent_health)
                                        print(oponent_alias+" herido. Su nivel de vida es "+oponent_health+"/100 puntos.")
        

        


    def cmd_vel_callback(msg):
        sim.setNamedFloatParam('cmd_vel_v_'+robotAlias,msg.linear.x)
        sim.setNamedFloataram('cmd_vel_w_'+robotAlias,msg.angular.z)

    def cmd_pos_callback (msg):
        p=[]
        p[0]=msg.x
        p[1]=msg.y
        p[2]=0
        goalDummyhandler= sim.getObject("/goalDummy"+robotAlias)
        sim.setObjectPosition(goalDummyhandler,-1,p)

    
# Implementación con Pool
#with multiprocessing.Pool(procesos) as pr_pool:
#    data = pr_pool.map(robot_thread,robots)

#GENERACION DE ROBOTS
# Implementación con process
def robotGen():
    global sceneData
    generator= sim.getObject('.')#poner path del dummy generador
    positions=[]
    if simROS2:
        ################# Quizas el subcriber va fuera o con una sola vez va bien
        subscriber_n_rob =simROS2.createSubscription("/create_robot","std_msgs/msg/String","create_robots_callback")
    dcamera= sim.getObject("/DefaultCamera")
    sim.setObjectSel({dcamera})
    #global n_robots
    n_robots=0
    global procs
    procs=[]
    poses=[]
    def create_robots_callback(msg):
        n_robots +=1
        print("[robot_Generator] Creating a new robot. Robot number "+n_robots+" named: "+ msg.data)
        file = sim.getStringParam(sim.stringparam_scene_path)+"/model_robot.ttm"
        robot= sim.loadModel(file) #### el load es un getobject en si 
        sim.setObjectParent(robot,generator,True)
        Alias="Robot_"+str(n_robots)
        sim.setObjectAlias(robot,Alias)
        # Inicio de un thread por cada robot
        p= multiprocessing.Process(target=robot_thread,args=(n_robots,robot))
        procs.append(p)

        p = sim.getObjectPosition(robot,-1)
        o = sim.getObjectOrientation(robot,-1)
        global poses
        while (not valid_pose(p,o)):
            p[0]=np.random.rand()*10-5
            p[1]=np.random.rand()*10-5
            o[3]= o[3]+np.pi()/2
            
        sceneData['robots'][Alias]['pose'][0]=p[0]
        sceneData['robots'][Alias]['pose'][1]=p[1]
        sceneData['robots'][Alias]['pose'][2]=o

        sim.setObjectPosition(robot,-1,p)
        sim.setObjectOrientation(robot,-1,o)

        poses[n_robots-1]=[p[0],p[1],o[3]]

        def valid_pose(pos,poses_):
            for i in range(len(poses_)):
                dist=np.linalg.norm(pos-poses_[i][:2])
                if dist<0.2:
                    return False
            return True

            
    

#procs=[]
#for i in robots:
 #   p = multiprocessing.Process(target=robot_thread,args=(i,handler))
  #  p.start() # Esto quizar tengo que lanzarlos desde abajo
   # procs.append(p)



# Cambia permanentemente la matriz poniendo dist si esta en rango o -1 en caso contrario

def Fov_array(rob,dic):
    global FOV_matrix
    for stuff in FOV_matrix:
        columns=len(FOV_matrix[stuff])
        for f in range(len(rob)):
            for c in range(len(columns)):
                if f == c:
                    FOV_matrix[f][c]=-1
                else:
                    ro=dic[stuff][str(rob[c])]['pose']
                    rt = dic[stuff][str(rob[f])]['pose'] if stuff == 'robots' else dic[stuff][str(rob[f])]['position']
                    x_local = (rt[0]-ro[0]) * np.cos(ro[2]) + (rt[1]-ro[1]) * np.sin(ro[2])
                    y_local = -(rt[0]-ro[0]) * np.sin(ro[2]) + (rt[1]-ro[1])* np.cos(ro[2])
                    local_o = np.arctan2(y_local,x_local)
                    dist = np.sqrt(x_local*x_local+y_local*y_local)
                    if dist<5 and abs(local_o)<(120*(np.pi()/180)):
                        FOV_matrix[f][c]=dist
                    else: 
                        FOV_matrix[f][c]=-1
    pass

#############################    MAIN    ##############################

FOV_thread= multiprocessing.Process(target=Fov_array,args=(robots,sceneData))
FOV_thread.start()
FOV_thread.join()
#for pr in procs:
 #   pr.join() #Espera a que se acaben para seguir con la simulación 

#Generacion de robots
while (not sim.getSimulationStopping()):# o game over
    #Lectura de Datos
    dataRead()
    #Actuacion
    for i in procs:
        i.start() # Se ejecutan los threads de los robots quizas vaya fuera por lo del while de dentro
    pass
    
# Cleanup functions

# sim.stopSimulaion()
#########################################################################