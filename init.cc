// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <stdio.h>
#include <allegro.h>
#include "init.hh"

void
check_args(int argc, char* argv[])
{
}

void
init()
{
  puts("Starting Initialisation");
  allegro_init();
  install_keyboard();
  install_timer();
  install_mouse();
  
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);

  show_mouse(screen);
  puts("Finished Initialisation");
}

/* EOF */
