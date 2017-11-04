#include <new.hpp>
#include <TMouse.hpp>
#include <TVideo.hpp>
#include <TEvent.hpp>
#include <TWindow.hpp>

extern "C" void initPS2(void);
namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];
			extern unsigned short * VideoMem;
			extern class TWindow ** windows;
			extern int TWindowHWND;
			TMouse::TMouse()
			{
				old_xpos = 0;  // old values
				old_ypos = 0;

				new_xpos = 0;  // new values
				new_ypos = 0;

				_mouse_x = 0;  px=0;
    			_mouse_y = 0;  py=0;

				video  = new TVideo;
			}
			TMouse::~TMouse() {
				delete video;
			}

			void TMouse::handleEvent(void)
			{
				memcpy(VideoMem,video->buffer,80*25*2*2);
    			mouse_handler();

    			// save mouse position
    			int tx = _mouse_x;
    			int ty = _mouse_y;
    			unsigned short svc = VideoMem[(80*ty)+tx];

    			// draw window's ...
    			memcpy(video->buffer,offscr,80*25*2*2);
    			windows[TWindowHWND-1]->handleEvent(video);

    			// restore mouse position
    			_mouse_x = tx;
    			_mouse_y = ty;
    			VideoMem[(80*ty)+tx] = svc;

    			if (buttons > 0)
    			{
    				for (int wid=0;wid<1;wid++)
    				{
   						windows[wid]->move(_mouse_x,_mouse_y);

   						video->setColor(14);
				        video->setCursorAtPos(33,10);
				        video->setString((char*)"->>> X:%d, Y:%d       ",_mouse_x, _mouse_y);
    				}
    			}

		        if (old_xpos > 79) { old_xpos = 79; } else
		        if (old_xpos <= 0) { old_xpos =  0; }

		        if (old_ypos > 24) { old_ypos = 24; } else
		        if (old_ypos <= 0) { old_ypos =  0; }

		        if (_mouse_x > 79) { _mouse_x = 79; } else
		        if (_mouse_x <= 0) { _mouse_x =  0; }

		        if (_mouse_y > 24) { _mouse_y = 24; } else
		        if (_mouse_y <= 0) { _mouse_y =  0; }


		        if (_mouse_x > old_xpos) { px = _mouse_x; } else
		        if (_mouse_x < old_xpos) { px = old_xpos; }


		        if (_mouse_y > old_ypos) { py = _mouse_y; } else
		        if (_mouse_y < old_ypos) { py = old_ypos; }

		        if (px > 79) { px = _mouse_x = 79; } else
		        if (px <= 0) { px = _mouse_x =  0; }

		        if (py > 24) { py = _mouse_y = 24; } else
		        if (py <= 0) { py = _mouse_y =  0; }

		        px = _mouse_x;
		        py = _mouse_y;

		        video->setCharAtPos(0xe102,px,py);
		        memcpy(VideoMem,video->buffer,80*25*2*2);

		        old_xpos = _mouse_x;
    			old_ypos = _mouse_y;
			}

			void TMouse::init(void)
			{
				initPS2();
			}
			void TMouse::draw(void)
			{
				memcpy(offscr,video->buffer,80*25*2*2);
			}
		}
	}
}