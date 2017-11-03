#ifndef _TSTREAM_H_
#define _TSTREAM_H_

#include <TVideo.hpp>
#include <string.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			extern class TStream cout;

			class TStream: public TString, public TVideo
			{
			public:
				explicit TStream();
				TStream& operator << (const ros::TString);
				TStream& operator << (char*);
				TStream& operator << (char);
				TStream& operator << (const char*);
			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header