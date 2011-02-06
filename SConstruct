import sys

env = Environment()

if sys.platform == 'darwin':
    pez_sources = ['#/src/libpez/pez.cocoa.m']
    env['FRAMEWORKS'] = ['Cocoa', 'OpenGL']
elif sys.platform == 'win32':
    pez_sources = ['#/src/libpez/pez.windows.c']
    env['LIBS'] = ['user32', 'gdi32', 'opengl32']

glew_sources = ['#/src/glew/glew.c']
mve_sources = ['#/src/main.c']
sources = mve_sources + pez_sources + glew_sources

env['CPPPATH'] = ['#/src/libpez', '#/src/glew']

env.Program('mve', sources) 
