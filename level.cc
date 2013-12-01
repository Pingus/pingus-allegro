// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details
#include <stdio.h>
 
#include <vector>
#include "level.hh"
#include "pingu.hh"
#include "playfield.hh"

int
play_level(int)
{
  bool quit = false;
  
  puts("Starting Level");
  Playfield playfield;
  puts("Playfield created");

  while(!quit) {
    if (keypressed()) {
      readkey();
      quit = true;
    }
    if (mouse_b & 1) {
      //show_mouse(NULL);
      circlefill(playfield.world.gfx_map, mouse_x, mouse_y, 10, 0);
      circlefill(playfield.world.col_map, mouse_x, mouse_y, 10, 0);
      //show_mouse(screen);
    } else if (mouse_b & 2) {
      puts("New Pingu");
      playfield.world.pingu.push_back(*(new Pingu(mouse_x, mouse_y)));
      puts("Happy Pinguing");
    } else if (mouse_b & 3) {
      puts("Wrong Button");
    }
      
    playfield.draw();
  }

  return 0;
}

/* EOF */
