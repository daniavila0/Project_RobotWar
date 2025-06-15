from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import TimerAction

nod2=TimerAction(period=5.0,actions=[    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_2"}],
    executable='elusive_player',
    name='Robot_2',
    arguments=['--ros-args', '--enclave', '/Robot_2']
    )])

nod3=TimerAction(period=10.0,actions=[    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_3"}],
    executable='elusive_player',
    name='Robot_3',
    arguments=['--ros-args', '--enclave', '/Robot_3']
    )])
nod4=TimerAction(period=15.0,actions=[    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_4"}],
    executable='elusive_player',
    name='Robot_4',
    arguments=['--ros-args', '--enclave', '/Robot_4']
    )])
nod5=TimerAction(period=20.0,actions=[    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_5"}],
    executable='elusive_player',
    name='Robot_5',
    arguments=['--ros-args', '--enclave', '/Robot_5']
    )])
nod6=TimerAction(period=25.0,actions=[    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_6"}],
    executable='elusive_player',
    name='Robot_6',
    arguments=['--ros-args', '--enclave', '/Robot_6']
    )])


def generate_launch_description():
   
   return LaunchDescription([
    Node(
    package='rosgame_players',
    parameters=[{"name":"warrior_1"}],
    executable='elusive_player',
    name='Robot_1',
    arguments=['--ros-args', '--enclave', '/Robot_1']
    ),
   nod2,nod3,nod4,nod5,nod6

   ])