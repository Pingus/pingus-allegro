// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#ifndef WORLD_HH
#define WORLD_HH

#include <vector>
#include <allegro.h>
#include "pingu.hh"

class World
{
public:
  World();
  ~World();
  void draw(BITMAP* scr);
  void save();
  void load();
  void init();
  void let_move();
  
  BITMAP* gfx_map;
  BITMAP* col_map;
  std::vector<Pingu> pingu;
  
private:
  //  vector<Start_Points>;
  //  vector<End_Points>;
};

#endif

/* EOF */
