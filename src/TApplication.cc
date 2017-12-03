#include <types.hpp>
#include <new.hpp>
#include <TApplication.hpp>
#include <TMenuBar.hpp>
#include <TStatusBar.hpp>
#include <TMouse.hpp>
#include <TWindow.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			unsigned short offscr[80*25*2*2];
			unsigned short * VideoMem = (unsigned short*)0xb8000;
			extern class TWindow **windows;
			extern unsigned short bupScreen[];
			extern unsigned short bup[];
			TApplication::TApplication(TVideo *_video)
			{
                video = _video;
			    
				deskTop = new TDeskTop(video);
				deskTop->init();
				deskTop->draw();
				
   				mouse = new TMouse(video);
				mouse->init();
				
				memcpy(bupScreen,VideoMem,80*25*2*2);
				memcpy(bup,VideoMem,80*25*2*2);
			}

			void TApplication::init(void) { }
			void TApplication::exec(void)
			{
				// ----------------
				// Event loop ...
				// ----------------
				for (;;)
			    {
				    mouse->handleEvent();
					windows[0]->handleEvent();
					
					memcpy(VideoMem,bup,80*25*2*2);
				}
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
