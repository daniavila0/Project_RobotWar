from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_1"}],
    executable='elusive_player',
    name='Robot_1',
    arguments=['--ros-args', '--enclave', '/Robot_1']
    ),
    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_2"}],
    executable='elusive_player',
    name='Robot_2',
    arguments=['--ros-args', '--enclave', '/Robot_2']
    ),

   ])