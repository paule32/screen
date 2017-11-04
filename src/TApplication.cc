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

			void TApplication::init(void) { }
			void TApplication::exec(void)
			{
				// ----------------
				// Event loop ...
				// ----------------
				for (;;) {
					mouse->handleEvent();

					//for (int w=0;w<TWindow::wno;w++)
					//windows[0]->handleEvent();
				}
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros