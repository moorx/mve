import sys

env = Environment()


if sys.platform == 'darwin':
    env['FRAMEWORKS'] = ['Cocoa', 'OpenGL']
    env['LINKFLAGS'] = ['-pagezero_size', '10000', '-image_base', '100000000']
elif sys.platform == 'win32':
    env['LIBS'] += ['user32', 'gdi32', 'opengl32']


glew_sources = ['#/src/glew/glew.c']
mve_sources = Glob('#/src/*.c')
sources = mve_sources + glew_sources


env['LIBPATH'] = ['#/src/glfw',
                  '#/src/luajit']

env['LIBS'] = ['glfw',
               'luajit']


env['CPPPATH'] = ['#/src/glfw',
                  '#/src/glew',
                  '#/src/luajit']

env['CPPDEFINES'] = ['GLEW_STATIC']

env.Program('mve', sources) 
