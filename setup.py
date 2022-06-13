import os
import re
import sys
import platform
import subprocess

from setuptools import setup, find_packages, Extension
from setuptools.command.build_ext import build_ext
#from distutils.version import LooseVersion


class CMakeExtension(Extension):
    def __init__(self, name, sourcedir=''):
        Extension.__init__(self, name, sources=[])
        self.sourcedir = os.path.abspath(sourcedir)

class CMakeBuild(build_ext):

    def run(self):
        try:
            out = subprocess.check_output(['cmake', '--version'])
        except OSError:
            raise RuntimeError("CMake must be installed to build the following extensions: " +
                               ", ".join(e.name for e in self.extensions))

        for ext in self.extensions:
            self.build_extension(ext)

    def build_extension(self, ext):

        ####### first build nymph and scarab #################################

        extdir = os.path.abspath(os.path.dirname(self.get_ext_fullpath(ext.name)))
        cmake_args = ['-DCMAKE_LIBRARY_OUTPUT_DIRECTORY=' + extdir,
                      '-DNymph_ENABLE_TESTING:bool=1',
                      '-DNymph_ENABLE_PYTHON:bool=1',
                      '-DScarab_BUILD_PYTHON:bool=1',
                      '-DTettigoniidae_ENABLE_PYTHON:bool=1',
                     ]

        cfg = 'Debug' if self.debug else 'Release'
        #cfg = 'DEBUG'
        build_args = ['--config', cfg]

        cmake_args += ['-DCMAKE_BUILD_TYPE=' + cfg]
        build_args += ['--', '-j2',]

        env = os.environ.copy()
        env['CXXFLAGS'] = '{} -DVERSION_INFO=\\"{}\\"'.format(env.get('CXXFLAGS', ''),
                                                              self.distribution.get_version())
        if not os.path.exists(self.build_temp):
            os.makedirs(self.build_temp)
        # We need to remove the cache file because pip makes new /tmp source directories each time
        print('remove cache')
        subprocess.check_call(['rm', '-f', 'CMakeCache.txt'], cwd=self.build_temp, env=env)
        print("should make a cmake call:")
        print(' '.join(['cmake', ext.sourcedir] + cmake_args), 'cwd={}'.format(self.build_temp), 'env={}'.format(env))
        subprocess.check_call(['cmake', ext.sourcedir] + cmake_args, cwd=self.build_temp, env=env)
        print("should make a build call:")
        print(['cmake', '--build', '.'] + build_args, 'cwd={}'.format(self.build_temp))
        #subprocess.check_call(['cmake', '--build', '.'] + build_args, cwd=self.build_temp)
        subprocess.check_call(['make', 'install'], cwd=self.build_temp)

        ######################################################################

        ######## next build tettigoniidae #####################################

        ######################################################################


if __name__ == "__main__":

    setup(
        ext_modules=[
            CMakeExtension('tettigoniidae',sourcedir='.')
            ],
        cmdclass=dict(build_ext=CMakeBuild),
        packages = find_packages(
            where='Python',
            include=['tettigoniidae']
        ),
        package_dir={'': 'Python'}
    )
