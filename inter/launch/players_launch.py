from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
   return LaunchDescription([
    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_1"}],
    executable='warrior_player',
    name='warrior_player_1',
    arguments=['--ros-args', '--enclave', '/Robot_1']
    ),
    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_2"}],
    executable='warrior_player',
    name='warrior_player_2',
    arguments=['--ros-args', '--enclave', '/Robot_2']
    ),

   ])