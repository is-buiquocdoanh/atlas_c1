from setuptools import find_packages
from setuptools import setup

setup(
    name='c1_driver',
    version='0.0.0',
    packages=find_packages(
        include=('c1_driver', 'c1_driver.*')),
)
