// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#ifndef PLAYFIELD_HH
#define PLAYFIELD_HH

//#include <oo-aleg.hh>
#include "gui_obj.hh"
#include "world.hh"

class Playfield : GuiObj
{
public:
  World world;
 
  Playfield();
  ~Playfield();
  void draw();

private:  
  int x_offset, y_offset;
  BITMAP* buffer;
};

#endif

/* EOF */
