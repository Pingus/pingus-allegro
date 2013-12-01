env = Environment(CXXFLAGS = [ '-O2', '-g' ], # , '-Wall', '-Werror', '-Wno-unused-result' ],
                  CPPDEFINES = [('VERSION', '\\"0.0.1\\"')],
                  LIBS     = [ 'alleg' ])
env.Program("pingus", ["pingus.cc",
                       "intro.cc",
                       "init.cc",
                       "game.cc",
                       "level.cc",
                       "world.cc",
                       "playfield.cc",
                       "pingu.cc",
                       "gui_obj.cc"])

# EOF #
