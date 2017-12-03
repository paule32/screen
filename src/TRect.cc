#include <TRect.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			TRect::TRect(void)
			{
				x = 0; y = 0;
				w = 0; h = 0;	
			}
			TRect::TRect(TRect &r)
			{
				rect = new TRect;
				rect->x = r.x;
				rect->y = r.y;

				rect->w = r.w;
				rect->h = r.h;
			}
			TRect::TRect(int x1, int y1, int w1, int h1)
			{
				x = x1; y = y1;
				w = w1; h = h1;
			}
			TRect::~TRect()
			{

			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros