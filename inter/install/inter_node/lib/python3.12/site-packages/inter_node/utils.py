import rclpy
from rclpy import node
from coppeliasim_zmqremoteapi_client import RemoteAPIClient
client=RemoteAPIClient()
sim = client.require('sim')

def robot_thread(handler):
    rclpy.init()
    node.get_logger().info(f'Estas lanzando el robot thread')