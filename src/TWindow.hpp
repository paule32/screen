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
				TWindow(TVideo *_video, class TRect &r);
				TWindow(TVideo *_video, class TRect *r);
				TWindow(TVideo *_video);
				~TWindow();

				void draw(void);
				void show(void);

				void move(int x, int y);

				void handleEvent();

				class TVideo * video;
				class TRect  * rect;
			};
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
#endif
