import sys

env = Environment()

if sys.platform == 'darwin':
    pez_sources = ['#/src/libpez/pez.cocoa.m']
    env['FRAMEWORKS'] = ['Cocoa', 'OpenGL']
elif sys.platform == 'win32':
    pez_sources = ['#/src/libpez/pez.windows.c']
    env['LIBS'] = ['user32', 'gdi32', 'opengl32']

lua_sources = Glob('#/src/lua/*.c')
glew_sources = ['#/src/glew/glew.c']
mve_sources = ['#/src/main.c']
sources = mve_sources + pez_sources + glew_sources + lua_sources

env['CPPPATH'] = ['#/src/libpez', 
                  '#/src/glew',
                  '#/src/lua']
env['CPPDEFINES'] = ['GLEW_STATIC']

env.Program('mve', sources) 
