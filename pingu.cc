// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <iostream>
//#include <stdio.h>
//#include <stdlib.h>
#include "pingu.hh"

Pingu::Pingu(int x, int y)
{
  cout << "Pingu.set_pos init" << endl;
  //  sprite = 0;
  alive = true;
  falling = 0;
  direction = left;
  //PALETTE pal;

  //sprite = load_pcx("images/pingu.pcx", pal);
  //  fall_sprite = load_pcx("images/PINGU_FALLing.PCX", pal);

  if (sprite == 0 || fall_sprite == 0) {
    //cerr << "Sceo" << endl;
    exit(1);
  }
  //set_palette(pal);
  cout << "Pingu.set_pos init ende" << endl;

  set_pos(x, y);
  falling = 0;
  //id = "New Set_Pos"; 
}

Pingu::Pingu()
{
  cout << "Pingu init" << endl;
  sprite = 0;
  alive = true;
  falling = 0;
  direction = left;
  //PALETTE pal;

  //sprite = load_pcx("images/pingu.pcx", pal);
  //fall_sprite = load_pcx("images/PINGU_FALLing.PCX", pal);

  if (sprite == 0 || fall_sprite == 0) {
    //fprintf(stderr, "Sceo\n");
    exit(1);
  }
  cout << "Pingu init ende" << endl;
  //id = "Normal";
}

Pingu::~Pingu()
{
  //  if (sprite) 
    //    destroy_bitmap(sprite);

}

void
Pingu::draw(/*BITMAP* scr*/)
{
  //putpixel(scr, x_pos, y_pos, rand()%255);
  if (falling > 2) {
    //draw_sprite(scr, fall_sprite, x_pos - sprite->w/2, y_pos-sprite->h);
  } else {
    if (direction == left) {
      // draw_sprite
	//	(scr, sprite, x_pos - sprite->w /2 ,  y_pos- sprite->h);
    } else {
      //draw_sprite_h_flip
      //	(scr, sprite, x_pos - sprite->w /2 ,  y_pos- sprite->h);
    }
  }
}

void 
Pingu::set_pos(int x, int y)
{
  x_pos = x;
  y_pos = y;
}

void change(int& dir)
{
  if (dir == left)
    dir = right;
  else
    dir =left;
}

int
Pingu::rel_getpixel(/*BITMAP* col_map,*/ int x, int y)
{/*
  return getpixel(col_map,
		  x_pos + (x * direction),
		  y_pos + y);*/
}


void
Pingu::let_move(void/*BITMAP* col_map*/)
{
  if (!alive)
    return;
  
  if (x_pos > 640)
    direction = left;

  if (x_pos < 0)
    direction = right;

  if (rel_getpixel(/*col_map,*/ 0, 1) == 0) {
    // Pingu is falling
    ++y_pos;
    ++falling;
    //printf("%s: %d Falling\n", id.c_str(), falling);
    
  } else {
    if (falling > 100) {
      alive = false;
      return;
  }    
  
    falling = 0;
    // Pingu is walking
    if (rel_getpixel(/*col_map,*/ 1, 0) == 0) {
      x_pos += direction;
      
    } else {
      if (rel_getpixel(/*col_map,*/ 1, -1) == 0) {
	--y_pos;
	x_pos += direction;
      } else if (rel_getpixel(/*col_map,*/ 1, -2) == 0) {
	y_pos -= 2;
	x_pos += direction;
      } else {
	change(direction);
      }
    }
  }
}

bool Pingu::is_alive(void)
{
  return alive;
}

/* EOF */
