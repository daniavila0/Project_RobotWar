from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

def generate_launch_description():
   nodB=TimerAction(period=5.0,actions=[    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_2"}],
    executable='fraud_player',
    name='Robot_2',
    arguments=['--ros-args', '--enclave', '/Robot_2']
    )])
   return LaunchDescription([
    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_1"}],
    executable='elusive_player',
    name='Robot_1',
    arguments=['--ros-args', '--enclave', '/Robot_1']
    ),
   nodB

   ])