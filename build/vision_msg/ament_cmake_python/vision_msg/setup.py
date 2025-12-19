from setuptools import find_packages
from setuptools import setup

setup(
    name='vision_msg',
    version='0.0.0',
    packages=find_packages(
        include=('vision_msg', 'vision_msg.*')),
)
