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
<<<<<<< HEAD
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

=======
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

				mouse = new TMouse;
				mouse->init();

				video->draw();
			}

>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
			void TApplication::init(void) { }
			void TApplication::exec(void)
			{
				// ----------------
				// Event loop ...
				// ----------------
<<<<<<< HEAD
				for (;;)
			    {
				    mouse->handleEvent();
					windows[0]->handleEvent();
					
					memcpy(VideoMem,bup,80*25*2*2);
=======
				for (;;) {
					mouse->handleEvent();

					//for (int w=0;w<TWindow::wno;w++)
					//windows[0]->handleEvent();
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
				}
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
<<<<<<< HEAD
}			// namespace ros
=======
}			// namespace ros
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
