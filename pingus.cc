// Copyright (C) 1998 Ingo Ruhnke <grumbel@gmx.de>, see README.TXT for details

#include <iostream>
#include <ClanLib/clanlib.h>
#include "init.hh"
#include "intro.hh"
#include "game.hh"
#include "pingus.hh"

class PingusMain : public CL_ClanApplication
{

public:
  /*
   char *get_title(void);
   void intro(void);
   void extro(void);
   void check_args(int argc, char* argv[]);
   int  main(int argc, char* argv[]);
  */

  virtual char* get_title()
    {
      return "Pingus";
    }
  
  void
  intro(void)
    {
      int x = 0;
      int flips = 0;

      cout << "Pingus Intro..." << endl;

      CL_Surface* menu = CL_Sprite::load("menu", datafile);
      CL_Surface* menu_quit = CL_Sprite::load("menu_quit", datafile);
      CL_Surface* menu_load = CL_Sprite::load("menu_load", datafile);
      CL_Surface* menu_start = CL_Sprite::load("menu_start", datafile);
      //CL_Display::set_palette("menu_pal", datafile);
      CL_Display::clear_display();
      menu->put_screen(0,0);
      CL_Display::flip_display();

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
	    menu_quit->put_screen(45,246);
	    break;

	  case 1:
	    menu_load->put_screen(45,300);

	    break;
	
	  case 2:
	    menu_start->put_screen(45,192);
	    break;
	  }
	  CL_Display::flip_display();
	  temp_pos = pos;
	}

	//    if (time + 1000 < CL_System::get_time()) {
	cout << "Flipping Display..." << endl;
	time = CL_System::get_time();
	//    }

	if (CL_System::keep_alive()) break;  
      }
    }

  void
  extro(void)
    {
      cout << "Pingus Extro..." << endl;
    }

  void 
  check_args(int argc, char* argv[])
    {
      cout << "Checking arguments..." << endl;
  
      cout << "Arguments correct" << endl;
    }

  virtual int main(int argc, char** argv)
    {
      cout << "Pingus " << VERSION << " starting..." << endl;

      //PingusMain::check_args(argc, argv);

      // initialisation
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
      return 0;
    }

private:
  CL_InputSourceProvider *datafile;

} my_app; // notice this line. It creates the global instance.

/* EOF */
