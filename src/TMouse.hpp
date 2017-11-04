#ifndef _TMOUSE_H_
#define _TMOUSE_H_

#include <TEvent.hpp>
#include <TVideo.hpp>

extern "C" {
extern void initPS2(void);
extern void mouse_handler(void);
extern short int _mouse_x;
extern short int _mouse_y;
};

namespace ros {
	namespace tui {
		namespace crt {
			class TMouse {
			public:
				TMouse();
				~TMouse();

				void handleEvent(void);

				void init(void);
				void draw(void);

				TVideo * video;

				unsigned char button;
				short int     new_xpos, old_xpos, px;
				short int     new_ypos, old_ypos, py;
			};
		}
	}
}
#endif