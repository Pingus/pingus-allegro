// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <iostream>
#include <allegro.h>
#include "init.hh"
#include "intro.hh"
#include "game.hh"
#include "level.hh"
#include "pingus.hh"
#include "playfield.hh"

class PingusMain
{

public:
  /*
   char *get_title(void);
   void intro(void);
   void extro(void);
   void check_args(int argc, char* argv[]);
   int  main(int argc, char* argv[]);
  */

  virtual const char* get_title()
    {
      return "Pingus";
    }
  
  void
  intro(void)
    {
      int x = 0;
      int flips = 0;

      std::cout << "Pingus Intro..." << std::endl;

#if 0
      //temp//CL_Surface* menu = CL_Sprite::load("menu", datafile);
      //temp//CL_Surface* menu_quit = CL_Sprite::load("menu_quit", datafile);
      //temp//CL_Surface* menu_load = CL_Sprite::load("menu_load", datafile);
      //temp//CL_Surface* menu_start = CL_Sprite::load("menu_start", datafile);
      //CL_Display::set_palette("menu_pal", datafile);
      //temp//CL_Display::clear_display();
      //temp//menu->put_screen(0,0);
      //temp//CL_Display::flip_display();

      int  time = CL_System::get_time();
      int  pos = 0;
      int  temp_pos = pos;
 
      while(CL_Keyboard::get_keycode(CL_Keyboard::KEY_SPACE)==false) {
      CL_Display::flip_display();
	if (CL_Keyboard::get_keycode(CL_Keyboard::KEY_UP) && pos < 3) {
	  ++pos;
	} else if (CL_Keyboard::get_keycode(CL_Keyboard::KEY_DOWN) && pos > (-1)) {
	  --pos;
	}

	if (temp_pos != pos) {
	  cout << pos << endl;
	  CL_Display::clear_display();
	  cout << "Clearing Display...." << endl;
	  menu->put_screen(0,0);
	
	  switch(pos) {
	  case 0:
	    //temp//menu_quit->put_screen(45,246);
	    break;

	  case 1:
	    //temp//menu_load->put_screen(45,300);

	    break;
	
	  case 2:
	    //temp//menu_start->put_screen(45,192);
	    break;
	  }
	  //temp//CL_Display::flip_display();
	  temp_pos = pos;
	}

	//    if (time + 1000 < CL_System::get_time()) {
	cout << "Flipping Display..." << endl;
	time = CL_System::get_time();
	//    }

	if (CL_System::keep_alive()) break;  
      }
#endif
    }

  void
  extro(void)
    {
      std::cout << "Pingus Extro..." << std::endl;
    }

  void 
  check_args(int argc, char* argv[])
    {
      std::cout << "Checking arguments..." << std::endl;
  
      std::cout << "Arguments correct" << std::endl;
    }

  virtual int main(int argc, char** argv)
    {
      std::cout << "Pingus " << VERSION << " starting..." << std::endl;

      //PingusMain::check_args(argc, argv);

      // initialisation
#if 0
      CL_System::init_display();
      CL_Display::set_videomode(640, 480, 8);
  
      datafile = CL_InputSourceProvider::create_datafile_provider("pingus.dat");

      cout << "Loading Data file...";
      CL_Surface* stopper = CL_Sprite::load("stopper", datafile);
      CL_Sprite("stopper", datafile);  
      cout << "finished" << endl;

      int scr_width = CL_Display::get_width();
      int scr_height = CL_Display::get_height();

      intro();

      cout << "Starting main loop" << endl;

      int x=0, y=0;
  
      while (CL_Keyboard::get_keycode(CL_Keyboard::KEY_ESCAPE) == false) {
	//    cout << CL_Input::mices[0]->get_mouse_x() << "--" 
	//	 << CL_Input::mices[0]->get_mouse_y() << endl;
	//stopper->put_screen(x,y);  
    
	CL_System::keep_alive(); // Do NOT forget this one...
      }
#endif
      return 0;
    }

private:
  //CL_InputSourceProvider *datafile;

};

int main(int argc, char** argv)
{
  std::cout << "Pingus " << VERSION << " starting..." << std::endl;

  init();
  play_level(1);

  allegro_exit ();

  return 0;
}

/* EOF */
