from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import SetEnvironmentVariable

def generate_launch_description():
   return LaunchDescription([
    Node(
    package='inter_node',
    #namespace='Broker',
    executable='broker_v3',
    name='Broker',
    arguments=['--ros-args', '--enclave', '/bridge'],
    output='screen'# muestra la salida en consola
    #parameters, interesante

    ),
    SetEnvironmentVariable('FASTRTPS_LOG_LEVEL', 'Error'),
    SetEnvironmentVariable('SECURITY_LOG_LEVEL', 'error'),
    Node(
    package='rosgame_bridge',
    #namespace='Bridge',
    executable='bridge',
    name='Bridge',
    arguments=['--ros-args', '--enclave', '/bridge', '--log-level', 'error']
    ),
   ])