#include <types.hpp>
#include <new.hpp>
#include <TStatusBar.hpp>
#include <TVideo.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];

			TStatusBar::TStatusBar()
			{
				video = new TVideo;
			}
			TStatusBar::~TStatusBar() { }

			void TStatusBar::init(void)
			{
				char txt[] = 
"  aaaaa                         ReactOS - Version 0.4.7                         ";
				
    			video->setCursorAtPos(0,24);
    			video->setColor(0xc0);
    			video->setString((char*)"%s",txt);
			}

			void TStatusBar::draw(void)
			{
	   			video->setCursorAtPos(0,0);
    			memcpy(offscr,video->buffer,80*25*2*2);
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros