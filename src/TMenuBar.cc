
#include <new.hpp>
#include <TMenuBar.hpp>
#include <TStream.hpp>
#include <string.hpp>

extern "C" void memset(void*,void*,size_t);
namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];

			TMenuBar::TMenuBar()
			{
				video = new TVideo;
			}
			TMenuBar::~TMenuBar() { }

			void TMenuBar::init(void)
			{
				char txt[] =
"                              ReactOS - Version 0.4.7                           ";

    			video->setCursorAtPos(0,0);
    			video->setColor(0xc0);
    			video->setString((char*)"%s",txt);
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