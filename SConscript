from building import *

cwd     = GetCurrentDir()
src     = Glob('*.c')
CPPPATH = [cwd]

group = DefineGroup('netinit', src, depend = ['PKG_USING_NETINIT'], CPPPATH = CPPPATH)

Return('group')
