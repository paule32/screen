#include <new.hpp>
#include <TMouse.hpp>
#include <TVideo.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];
			TMouse::TMouse()
			{
				video = new TVideo;
				event = new TEvent;

				event->mouse.posX = 0;
				event->mouse.posY = 0;

				init();
			}
			TMouse::~TMouse() {
				delete video;
				delete event;
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