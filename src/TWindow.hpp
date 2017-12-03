#ifndef _TWINDOW_H_
#define _TWINDOW_H_

#include <types.hpp>
#include <TVideo.hpp>
#include <TRect.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			extern class TWindow **windows;
			extern int TWindowHWND;
			class TWindow {
			public:
<<<<<<< HEAD
				TWindow(TVideo *_video, class TRect &r);
				TWindow(TVideo *_video, class TRect *r);
				TWindow(TVideo *_video);
=======
				TWindow(class TRect &r);
				TWindow(class TRect *r);
				TWindow();
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
				~TWindow();

				void draw(void);
				void show(void);

				void move(int x, int y);

<<<<<<< HEAD
				void handleEvent();
=======
				void handleEvent(TVideo *video);
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290

				class TVideo * video;
				class TRect  * rect;
			};
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
