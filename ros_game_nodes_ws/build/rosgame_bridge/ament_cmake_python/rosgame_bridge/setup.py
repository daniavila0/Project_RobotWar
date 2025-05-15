from setuptools import find_packages
from setuptools import setup

setup(
    name='rosgame_bridge',
    version='0.0.0',
    packages=find_packages(
        include=('rosgame_bridge', 'rosgame_bridge.*')),
)
