// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <iostream>
#include <stdio.h>
#include "playfield.hh"

Playfield::Playfield()
{
  std::cout << "Playfield:init" << std::endl;
  world.init();
  buffer = create_bitmap(640,480);
}

Playfield::~Playfield()
{
}

void
Playfield::draw()
{
  world.let_move();
  world.draw(buffer);

  blit(buffer, screen, 0,0,0,0, 640, 480);
  
  //  GuiObj::draw();
}

/* EOF */
