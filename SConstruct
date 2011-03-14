import sys

if sys.platform == 'win32':
    env = Environment(TARGET_ARCH = 'x86')
else:
    env = Environment()


if sys.platform == 'darwin':
    env['FRAMEWORKS'] = ['Cocoa', 'OpenGL']
    env['LINKFLAGS'] = ['-pagezero_size', '10000', '-image_base', '100000000']
    env['LIBPATH'] = ['#/src/glfw/mac',
                      '#/src/luajit/mac']
    env['LIBS'] = ['luajit']

elif sys.platform == 'win32':
    env['LIBS'] = ['user32', 'gdi32', 'opengl32', 'lua51']
    env['LIBPATH'] = ['#/src/glfw/win',
                      '#/src/luajit/win']
    env['CCFLAGS'] = ['/TP', '/MD']

glew_sources = ['#/src/glew/glew.c']
mve_sources = Glob('#/src/*.c')
sources = mve_sources + glew_sources


env['LIBS'] += ['glfw']


env['CPPPATH'] = ['#/src/glfw',
                  '#/src/glew',
                  '#/src/luajit']

env['CPPDEFINES'] = ['GLEW_STATIC']

env.Program('mve', sources) 
