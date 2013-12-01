// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <assert.h>
#include <vector>
#include <stdio.h>
//#include <oo-aleg.hh>
#include "world.hh"

World::World()
{
  puts("World init");
  gfx_map = col_map = 0;
  pingu.resize(50);
  puts("World init ende");
}

World::~World()
{
}

void 
World::draw(BITMAP* scr)
{
  if (gfx_map) {
    //puts("Blinting");

    blit(gfx_map, scr, 0,0,0,0,640,480);
    
    for(int i=0; i < pingu.size(); ++i) {
      pingu[i].draw(scr);
    }
  }
  //printf("%d Pingus alive, Jea\n", pingu.size());
}

void 
World::let_move()
{
  //puts("World::let_move");
  for(int i=0; i < pingu.size(); ++i) {
    //puts("Penu::let_move");
    pingu[i].let_move(col_map);
  }
}

void 
World::save()
{
}

void 
World::load()
{
}

void 
World::init()
{
  for(int i=0; i < pingu.size(); ++i) {
      pingu[i].set_pos(i*12 + 10, 175);
  }
  puts("World init : loading gfx");
  gfx_map = load_pcx("levels/1_gfx.pcx", NULL);
  assert(gfx_map);
  
  int conversion_mode = get_color_conversion();
  set_color_conversion(COLORCONV_NONE);
  col_map = load_pcx("levels/1.pcx", NULL);
  set_color_conversion(conversion_mode);
  assert(col_map);
  puts("World init : finished");
}

/* EOF */
