
#include <new.hpp>
#include <TMenuBar.hpp>
#include <TStream.hpp>
#include <string.hpp>

extern "C" void memset(void*,void*,size_t);
namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];

<<<<<<< HEAD
			TMenuBar::TMenuBar(TVideo *_video)
			{
				video = _video;
			}
			TMenuBar::~TMenuBar() { }

			void TMenuBar::init()
			{

			}

			void TMenuBar::draw(void)
			{
    			char txt[] =
=======
			TMenuBar::TMenuBar()
			{
				video = new TVideo;
			}
			TMenuBar::~TMenuBar() { }

			void TMenuBar::init(void)
			{
				char txt[] =
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
"                              ReactOS - Version 0.4.7                           ";

    			video->setCursorAtPos(0,0);
    			video->setColor(0xc0);
    			video->setString((char*)"%s",txt);
<<<<<<< HEAD

    			//memcpy(offscr,video->buffer,80*2);
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
=======
			}

			void TMenuBar::draw(void)
			{
	   			//setCursorAtPos(0,0);
    			memcpy(offscr,video->buffer,80*25*2*2);

				//for(;;){}
				//memcpy(VideoMem,buffer,80);
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
