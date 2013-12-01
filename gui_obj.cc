// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include "gui_obj.hh"
#include <allegro.h>

GuiObj::GuiObj()
{
  bmp = create_bitmap(640, 480);
}

GuiObj::~GuiObj()
{
  destroy_bitmap(bmp);
}

void
GuiObj::draw(BITMAP* scr)
{
  blit(bmp, screen, x1, y1, x2, y2, x2 - x1, y2 - y1);
}

void
GuiObj::draw()
{
  GuiObj::draw(screen);
}

/* EOF */
