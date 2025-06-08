from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
    Node(
    package='inter_node',
    #namespace='Broker',
    executable='broker',
    name='Broker',
    arguments=['--ros-args', '--enclave', '/bridge'],
    output='screen'# muestra la salida en consola
    #parameters, interesante

    ),
    Node(
    package='rosgame_bridge',
    #namespace='Bridge',
    executable='bridge',
    name='Bridge',
    arguments=['--ros-args', '--enclave', '/bridge']
    ),
   ])