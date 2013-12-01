// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <vector>
#include <stdio.h>
//#include <oo-aleg.hh>
#include "world.hh"

World::World()
{
  puts("World init");
  //  gfx_map = col_map = 0;
  //pingu.resize(100);
  //puts("World init ende");
}

World::~World()
{
}

void 
World::draw(/*BITMAP* scr*/)
{
  if (/*gfx_map*/1) {
    //puts("Blinting");

    // blit(gfx_map, scr, 0,0,0,0,640,480);
    /*
    for(int i=0; i < pingu.size(); ++i) {
      pingu[i].draw(scr);
    }*/
  }
  //printf("%d Pingus alive, Jea\n", pingu.size());
}

void 
World::let_move()
{
  //puts("World::let_move");
  for(int i=0; i < pingu.size(); ++i) {
    //puts("Penu::let_move");
    pingu[i].let_move(/*col_map*/);
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
  /*PALETTE*/ int pal;

  //for(int i=0; i < pingu.size(); ++i) {
  //    pingu[i].set_pos(i*6 + 10, 175);
    //  }
  puts("World init : loading gfx");
  //  gfx_map = load_pcx("levels/1_gfx.pcx", pal);
  //set_palette(pal);

  //col_map = load_pcx("levels/1.pcx", pal);
  puts("World init : finished");
}

/* EOF */
