#ifndef _TEVENT_H__
#define _TEVENT_H__

#include <TMouse.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			struct TEventMouse {
				unsigned char button;
				short int     posX;
				short int     posY;
			};
			class TEvent {
			public:
				TEvent();
				~TEvent();

				class TEvent * exec(class TMouse*);

				TEventMouse mouse;
			};
		}
	}
}
#endif