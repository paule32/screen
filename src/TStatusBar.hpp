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
<<<<<<< HEAD
				explicit TStatusBar(TVideo *_video);
=======
				explicit TStatusBar();
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
				~TStatusBar();

				void init();
				void draw();

				TVideo *video;
			};
		}	// namespacr ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
<<<<<<< HEAD
#endif		// header
=======
#endif		// header
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
