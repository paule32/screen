#ifndef TMENUBAR_H_
#define TMENUBAR_H_

#include <types.hpp>
#include <TObject.h>
#include <TVideo.hpp>
#include <TDesktop.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			class TMenuBar
			{
			public:
				explicit TMenuBar();
				~TMenuBar();

				void init();
				void draw();

				TVideo * video;
			};
		}	// namespacr ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header