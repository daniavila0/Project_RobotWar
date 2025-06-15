from setuptools import find_packages, setup
import os

package_name = 'inter_node'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml'])
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='daniel',
    maintainer_email='daniel@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'broker = inter_node.inter_node:main',
            'broker_v2=inter_node.inter_node_v2:main',
            'broker_v3=inter_node.inter_node_v3:main'
            #name = pkg_name.file_name:main
        ],
    },
)
