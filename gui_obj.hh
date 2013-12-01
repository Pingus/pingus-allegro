// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#ifndef GUI_OBJ_HH
#define GUI_OBJ_HH

//#include <allegro.h>

class GuiObj 
{
public:
  GuiObj();
  ~GuiObj();
  //BITMAP* bmp;

  // virtual void draw(/*BITMAP* scr*/);
  virtual void draw();
  
private:
  int x1, y1, x2, y2;
};

#endif

/* EOF */
