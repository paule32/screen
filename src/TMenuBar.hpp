#ifndef TMENUBAR_H_
#define TMENUBAR_H_

#include <types.hpp>
#include <TObject.h>
#include <TVideo.hpp>
<<<<<<< HEAD
=======
#include <TDesktop.hpp>
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290

namespace ros {
	namespace tui {
		namespace crt {
			class TMenuBar
			{
			public:
<<<<<<< HEAD
				explicit TMenuBar(TVideo *_video);
=======
				explicit TMenuBar();
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
				~TMenuBar();

				void init();
				void draw();

				TVideo * video;
			};
		}	// namespacr ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
<<<<<<< HEAD
#endif		// header
=======
#endif		// header
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
