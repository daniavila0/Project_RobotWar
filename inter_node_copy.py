import multiprocessing
import rclpy
from rclpy.node import Node

import time
import numpy as np
import json

from coppeliasim_zmqremoteapi_client import RemoteAPIClient
client=RemoteAPIClient()
sim = client.require('sim')

from std_msgs.msg import String
#from std_msgs import Int32
#from geometry_msgs import Twist
#from geometry_msgs import Point
#from sensor_msgs import laser_scan
#from rosgame_msgs import rosgame_twist
#from rosgame_msgs import rosgame_point


class Broker (Node):
        
    def __init__(self):
        super().__init__('my_broker')
        self.publisher_=self.create_publisher(String,'/scene_info',10)
        self.robot_gen= self.create_subscription(String,'/create_robot',self.callback_robot_gen,10)
        self.robot_gen
        # VARS
        self.n_robots=0
        self.handlers=[]
        self.sceneData = multiprocessing.Manager().dict()
        self.sceneData["Robots"] = []
        self.sceneData["Chargers"] = []
        self.sceneData["Skills"] = []
        self.sceneData["Obstacles"] = []
        self.processes=[]
        self.timer = self.create_timer(0.5, self.calculateFOV) #Calcula la matriz de distancias 2 veces por segundo
        self.FOV_matrix=multiprocessing.Manager().dict()

    def callback_robot_gen(self,msg):
        self.get_logger().info('I heard: "%s"' % msg.data)
        #global sceneData
        self.n_robots +=1
        print("[robot_Generator] Creating a new robot. Robot number "+str(self.n_robots)+" named: "+ msg.data)
        file = '/home/daniel/Documentos/Project_ws/my_project/game_scene/model_robot.ttm'
        robot= sim.loadModel(file) #### el load es un getobject en si 
        self.handlers.append(robot)  # Pila de manejadores
        sim.setObjectAlias(robot,"Robot_"+str(self.n_robots))
        # poses
        def valid_pose(pos,poses_):
                for i in range(len(poses_)):
                    dist = np.linalg.norm(np.array(pos) - np.array(poses_[i][:2]))
                    if dist<0.2:
                        return False
                return True
        poses = self.get_all_positions()
        p = sim.getObjectPosition(robot,-1)
        o = sim.getObjectOrientation(robot,-1)
        while (not valid_pose(p[:2],poses)):
                p[0]=np.random.rand()*10-5
                p[1]=np.random.rand()*10-5
                o[2]= o[2]+np.pi/2
        # p[2]= 0
        sim.setObjectPosition(robot,-1,p)
        sim.setObjectOrientation(robot,-1,o)
        
        self.sceneData["Robots"].append({"Alias": sim.getObjectAlias(self.handlers[self.n_robots-1]),
                                         "Battery": 100,
                                         "Pose":[p[0],p[1],o]})
        
        simple_scene_data = {
        "Robots": list(self.sceneData["Robots"]),
        "Chargers": list(self.sceneData["Chargers"]),
        "Skills": list(self.sceneData["Skills"]),
        "Obstacles": list(self.sceneData["Obstacles"]),
        }
        scene_data_json = json.dumps(simple_scene_data)
        sim.setBufferProperty(sim.handle_scene, "customData.myTag", json.dumps(simple_scene_data))

        #MULTIPROCESSING
        p=multiprocessing.Process(target=robot_thread,args=["Robot_"+str(self.n_robots)]) #argumento es el handler
        p.start()
        self.processes.append(p) #Crear una lista de procesos es importante
        
        
        #Leer datos
        #data = json.loads(sim.getBufferProperty(sim.handle_scene, "customData.myScene"))
        #print(data["robots"])
        
    def get_all_positions(self):
            posiciones = []
            for categoria in ["Robots", "Chargers", "Skills", "Obstacles"]:
                for objeto in self.sceneData[categoria]:
                    if (categoria=="Robots"):
                        posiciones.append(objeto["Pose"][:2]) 
                    else:
                        posiciones.append(objeto["Position"][:2])  # solo x, y si hay más valores
            return posiciones
    
    def calculateFOV(self): # Aqui no se si se estan actualizando
        scene_copy = {
        "Robots": list(self.sceneData["Robots"]),
        "Chargers": list(self.sceneData["Chargers"]),
        "Skills": list(self.sceneData["Skills"]),
        "Obstacles": list(self.sceneData["Obstacles"]),
        }
        fovmat = multiprocessing.Manager().dict()
        calc = multiprocessing.Process(target=Fov_array, args=(scene_copy, fovmat))
        calc.start()


def Fov_array(sceneData, FOV_matrix):
    def get_positions(lista):
        return np.array([obj["Pose"][:2] if "Pose" in obj else obj["Position"][:2] for obj in lista]) if lista else np.empty((0, 2))

    robots_pos = get_positions(sceneData["Robots"])
    chargers_pos = get_positions(sceneData["Chargers"])
    skills_pos = get_positions(sceneData["Skills"])
    obstacles_pos = get_positions(sceneData["Obstacles"])

    for i, robot in enumerate(sceneData["Robots"]):
        alias = robot["Alias"]
        pos = robots_pos[i]

        FOV_matrix[alias] = {
            "robots": [],
            "chargers": [],
            "skills": [],
            "obstacles": []
        }

        for j, other_pos in enumerate(robots_pos):
            if i == j:
                continue
            d = np.linalg.norm(pos - other_pos)
            FOV_matrix[alias]["robots"].append(d if d <= 5 else -1)

        for name, positions in [("chargers", chargers_pos), ("skills", skills_pos), ("obstacles", obstacles_pos)]:
            dist_list = []
            for obj_pos in positions:
                d = np.linalg.norm(pos - obj_pos)
                dist_list.append(d if d <= 5 else -1)
            FOV_matrix[alias][name] = dist_list



def robot_thread(name):
    rclpy.init()
    class RobotNode(Node):
        def __init__(self):
            super().__init__('robot_thread_node')
            self.handler=sim.getObject(f'/{name}')

    node = RobotNode()
    node.get_logger().info(f'Estas lanzando el robot thread de {name}')

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown() 




def main(args=None):
    multiprocessing.set_start_method('spawn')
    # Esto es necesario porque con multiprocessing en fork no lo hace limpio el proceso
    #y hereda lo del padre
    rclpy.init(args=args)
    node = Broker()
    rclpy.spin(node)

if __name__ == '__main__':
    main()