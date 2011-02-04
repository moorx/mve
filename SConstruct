import sys

if sys.platform == 'darwin':
    pez_sources = ['#/src/libpez/pez.cocoa.m']
    frameworks = ['Cocoa', 'OpenGL']

glew_sources = ['#/src/glew/glew.c']
mve_sources = ['#/src/main.c']
sources = mve_sources + pez_sources + glew_sources

header_paths = ['#/src/libpez', '#/src/glew']

Program('mve', sources, CPPPATH = header_paths, FRAMEWORKS = frameworks)
