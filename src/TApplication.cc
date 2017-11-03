#include <new.hpp>
#include <TApplication.hpp>
#include <TMenuBar.hpp>
#include <TStatusBar.hpp>

extern "C" {
extern void memset(void*,void*,size_t);

extern void initPS2(void);
extern void mouse_handler(void);
extern short int _mouse_x;
extern short int _mouse_y;

extern char buttons; 
};

namespace ros {
	namespace tui {
		namespace crt {
			unsigned short offscr[80*25*2*2];
			unsigned short * VideoMem = (unsigned short*)0xb8000;
			TApplication::TApplication(void)
			{
				deskTop = new TDeskTop;
				deskTop->init();
				deskTop->draw();

				menuBar = new TMenuBar;
				menuBar->init();
				menuBar->draw();
				
				statusBar = new TStatusBar;
				statusBar->init();
				statusBar->draw();

				video = new TVideo;
				video->init();

				memcpy(video->buffer,offscr,80*25*2*2);
			}

			void TApplication::init(void)
			{
				
			}

			void TApplication::exec(void)
			{
			    static unsigned short old_mx = 0;
			    static unsigned short old_my = 0;
			    int px = 0;
			    int py = 0;

				memcpy(VideoMem,video->buffer,80*25*2*2);
			    initPS2();

				for(;;)
				{
					memcpy(VideoMem,video->buffer,80*25*2*2);
					mouse_handler();
					
					memcpy(video->buffer,offscr,80*25*2*2);

					video->setColor(14);
			        video->setCursorAtPos(33,10);
			        video->setString((char*)"->>> X:%d, Y:%d       ",_mouse_x, _mouse_y);
        			
        			video->setCursorAtPos(33,11);
					switch (buttons) {
			        case 0:  video->setString((char*)"no button pressd             ");
			                 break;
			        case 1:  video->setString((char*)"button >%d<: pressed links   ",buttons);
			                 break;
			        case 2:  video->setString((char*)"button >%d<: pressed rechts  ",buttons);
			                 break;
			        case 3:  video->setString((char*)"button >%d<: pressed mitte   ",buttons);
			                 break;
			        case 4:  video->setString((char*)"button >%d<: test case       ",buttons);
			                 break;
			        default: video->setString((char*)"button >%d<: not pressed     ",buttons);
			                 break;
			        }

			        if (old_mx > 79) { old_mx = 79; } else
			        if (old_mx <= 0) { old_mx =  0; }

			        if (old_my > 24) { old_my = 24; } else
			        if (old_my <= 0) { old_my =  0; }

			        if (_mouse_x > 79) { _mouse_x = 79; } else
			        if (_mouse_x <= 0) { _mouse_x =  0; }

			        if (_mouse_y > 24) { _mouse_y = 24; } else
			        if (_mouse_y <= 0) { _mouse_y =  0; }

			        if (_mouse_x > old_mx) { px = _mouse_x; } else
			        if (_mouse_x < old_mx) { px = old_mx;   }


			        if (_mouse_y > old_my) { py = _mouse_y; } else
			        if (_mouse_y < old_my) { py = old_my;   }

			        if (px > 79) { px = _mouse_x = 79; } else
			        if (px <= 0) { px = _mouse_x =  0; }

			        if (py > 24) { py = _mouse_y = 24; } else
			        if (py <= 0) { py = _mouse_y =  0; }

			        px = _mouse_x;
			        py = _mouse_y;

			        video->setCharAtPos(0xe102,px,py);
			        memcpy(VideoMem,video->buffer,80*25*2*2);

			        //memcpy(scrn,offscr,80*25*2*2);
			        //scrn[(py*80)+px] = 0xe102;
			        //memcpy(video->VideoMem,scrn,80*25*2*2);

			        old_mx = _mouse_x;
        			old_my = _mouse_y;
				}
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros