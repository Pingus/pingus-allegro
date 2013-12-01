// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <stdio.h>
#include "game.hh"
#include "level.hh"

int
menu()
{
  puts("Menu - you don't have a choice");
}

void
game(void)
{
  puts("Game - The fun starts");
  switch (menu()) {
  default:
    play_level(1);
    break;
  }
}

/* EOF */
