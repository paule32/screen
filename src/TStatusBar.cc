#include <types.hpp>
#include <new.hpp>
#include <TStatusBar.hpp>
#include <TVideo.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];

<<<<<<< HEAD
			TStatusBar::TStatusBar(TVideo *_video)
			{
				video = _video;
=======
			TStatusBar::TStatusBar()
			{
				video = new TVideo;
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
			}
			TStatusBar::~TStatusBar() { }

			void TStatusBar::init(void)
			{
<<<<<<< HEAD

			}

			void TStatusBar::draw(void)
			{
=======
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
				char txt[] = 
"  aaaaa                         ReactOS - Version 0.4.7                         ";
				
    			video->setCursorAtPos(0,24);
    			video->setColor(0xc0);
<<<<<<< HEAD
    			video->setString((char*)"%s",txt);			
    			
=======
    			video->setString((char*)"%s",txt);
			}

			void TStatusBar::draw(void)
			{
	   			video->setCursorAtPos(0,0);
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
    			memcpy(offscr,video->buffer,80*25*2*2);
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
<<<<<<< HEAD
}			// namespace ros
=======
}			// namespace ros
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
