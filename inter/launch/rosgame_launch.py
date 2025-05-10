from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
    Node(
    package='inter_node',
    #namespace='Broker',
    executable='broker',
    name='Broker',
    output='screen',# muestra la salida en consola
    #parameters, interesante

    ),
    Node(
    package='rosgame_bridge',
    #namespace='Bridge',
    executable='bridge',
    name='Bridge',
    arguments=['--ros-args', '--enclave', '/bridge']
    ),
    Node(
    package='rosgame_player',
    #namespace='e1',
    executable='elusive_player',
    name='elusive_player_1',
    arguments=['--ros-args', '--enclave', '/player']
    ),
    Node(
    package='rosgame_player',
    #namespace='e2',
    executable='elusive_player',
    name='elusive_player_2',
    arguments=['--ros-args', '--enclave', '/player']
    ),
    Node(
    package='rosgame_player',
    #namespace='e3',   esto funciona como los dominios para que no se pisen
    executable='elusive_player',
    name='elusive_player_3',
    arguments=['--ros-args', '--enclave', '/player']
    ),
   ])