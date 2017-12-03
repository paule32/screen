
#include <new.hpp>
#include <TMenuBar.hpp>
#include <TStream.hpp>
#include <string.hpp>

extern "C" void memset(void*,void*,size_t);
namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];

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
"                              ReactOS - Version 0.4.7                           ";

    			video->setCursorAtPos(0,0);
    			video->setColor(0xc0);
    			video->setString((char*)"%s",txt);

    			//memcpy(offscr,video->buffer,80*2);
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
