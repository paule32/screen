#include <new.hpp>
#include <TMouse.hpp>
#include <TVideo.hpp>
#include <TEvent.hpp>
#include <TWindow.hpp>

extern "C" void initPS2(void);
extern     void format_volume(int);

namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];
			extern unsigned short * VideoMem;
			extern class TWindow ** windows;
			extern int TWindowHWND;
			unsigned short bupScreen[80*25*2*2];
            unsigned short bup[80*25*2*2];
			TMouse::TMouse(TVideo *_video)
			{
				old_xpos = 0;  // old values
				old_ypos = 0;

				new_xpos = 0;  // new values
				new_ypos = 0;

				_mouse_x = 0;  px=0;
    			_mouse_y = 0;  py=0;

				video  = _video;
			}
			TMouse::~TMouse() {
				//delete video;
			}

			void TMouse::handleEvent()
			{
                mouse_handler();

                memcpy(bup,bupScreen,80*25*2*2);
                bup[(80*_mouse_y)+_mouse_x] = 0xe102;
                
                if (_mouse_x <  0) _mouse_x =  0;
                if (_mouse_x > 79) _mouse_x = 79;
                
                if (_mouse_y <  0) _mouse_y =  0;
                if (_mouse_y > 24) _mouse_y = 24;
                 			
    			if (buttons > 0)
    			{
    				//for (int wid=0;wid<1;wid++)
    				{
                        memcpy(offscr,bupScreen,80*25*2*2);
   						windows[0]->move(_mouse_x,_mouse_y);  // <-- als Hilfe: die box soll verschoben werden
   						
   						memcpy(offscr,windows[0]->video->buffer,80*25*2*2);
                        offscr[(80*_mouse_y)+_mouse_x] = 0xe102;
                    }
                }
			}

			void TMouse::init(void)
			{
				initPS2();
			}
			void TMouse::draw(void)
			{
				//memcpy(offscr,video->buffer,80*25*2*2);
			}
		}
	}
}

