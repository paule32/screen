#ifndef _TRECT_H_
#define _TRECT_H_

#include <types.hpp>
namespace ros {
	namespace tui {
		namespace crt {
			class TRect {
			public:
				TRect(int,int,int,int);
				TRect(TRect &);
				TRect();
				
				~TRect();

				class TRect * rect;
				int x,y,w,h;
			};
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
#endif