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
<<<<<<< HEAD
				TMouse(TVideo *_video);
				~TMouse();

				void handleEvent();
				
				TVideo *video;
=======
				TMouse();
				~TMouse();

				void handleEvent(void);
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290

				void init(void);
				void draw(void);

<<<<<<< HEAD
				unsigned char button;
				short int     new_xpos, old_xpos, px;
				short int     new_ypos, old_ypos, py;
		
		        uint16_t   svc;
=======
				TVideo * video;

				unsigned char button;
				short int     new_xpos, old_xpos, px;
				short int     new_ypos, old_ypos, py;
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
			};
		}
	}
}
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
