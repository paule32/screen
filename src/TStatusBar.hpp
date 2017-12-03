#ifndef TSTATUSBAR_H_
#define TSTATUSBAR_H_

#include <types.hpp>
#include <TObject.h>
#include <TVideo.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			class TStatusBar
			{
			public:
				explicit TStatusBar(TVideo *_video);
				~TStatusBar();

				void init();
				void draw();

				TVideo *video;
			};
		}	// namespacr ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header
