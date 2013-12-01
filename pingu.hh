// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#ifndef PINGU_HH
#define PINGU_HH

#include <Clanlib/clanlib.h>
#include <string>
//#include <allegro.h>

//enum Direction { left = -1, right = 1 };
#define left (-1)
#define right 1

enum Action {};
enum Action2 {};

class Pingu
{
public:
  Pingu();
  Pingu(int x, int y);
  ~Pingu();

  int  rel_getpixel(/*BITMAP* col_map,*/ int x, int y);
  void set_pos(int x, int y);
  void let_move(/*BITMAP* col_map*/);
  void draw(/*BITMAP* scr*/);
  bool is_alive(void);

private:
  bool alive;
  int x_pos, y_pos;
  int falling;
  int direction;
  //string id;
  
  Action  action;
  Action2 action2;
  int/*BITMAP**/ sprite;
  int/*BITMAP**/ fall_sprite; 
};

#endif

/* EOF */
