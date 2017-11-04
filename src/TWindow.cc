#include <new.hpp>
#include <TWindow.hpp>
#include <TRect.hpp>
#include <TVideo.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			extern unsigned short offscr[];
			extern unsigned short * VideoMem;
			class TWindow **windows;
			int TWindowHWND = 0;
			TWindow::TWindow() { }
			TWindow::TWindow(class TRect *r)
			{
				video = new TVideo;
				rect  = new TRect;

				rect = r;
				rect->x = r->x;
				rect->y = r->y;
				rect->w = r->w;
				rect->h = r->h;

				windows[TWindowHWND++] = this;
			}
			TWindow::TWindow(class TRect &r)
			{
				video = new TVideo;
				rect  = new TRect;

				rect->x = r.x;
				rect->y = r.y;
				rect->w = r.w;
				rect->h = r.h;

				windows[TWindowHWND++] = this;
			}
			TWindow::~TWindow()
			{
				delete rect;
				delete video;
			}
			void TWindow::show(void)
			{
				//draw();
				//memcpy(VideoMem,video->buffer,80*25*2*2);
			}
			void TWindow::move(int x, int y)
			{
				rect->x = x;
				rect->y = y;

				draw();
			}
			void TWindow::draw(void)
			{
				unsigned char color = 0x1e;
				unsigned short attr = (color << 8) | 201;
				video->setCharAtPos(attr,rect->x  ,rect->y); attr = (color << 8) | 205;
				video->setCharAtPos(attr,rect->x+1,rect->y); attr = (color << 8) | '[';
				video->setCharAtPos(attr,rect->x+2,rect->y); attr = (color << 8) | 254;
				video->setCharAtPos(attr,rect->x+3,rect->y); attr = (color << 8) | ']';
				video->setCharAtPos(attr,rect->x+4,rect->y); attr = (color << 8) | 205;

				for (int i=0;i<rect->w;i++) {
					video->setCharAtPos(attr,rect->x+5+i,rect->y);
					video->setCharAtPos(attr,rect->x+5+i,rect->y+rect->h);
				}

				video->setCharAtPos(attr,rect->x+1,rect->y+rect->h);
				video->setCharAtPos(attr,rect->x+2,rect->y+rect->h);
				video->setCharAtPos(attr,rect->x+3,rect->y+rect->h);
				video->setCharAtPos(attr,rect->x+4,rect->y+rect->h);

				attr = (color << 8) | 186;

				for (int i=1;i<rect->h;i++) {
					video->setCharAtPos(attr,rect->x,rect->y+i);
					video->setCharAtPos(attr,rect->x+rect->w+5,rect->y+i);
				}

				attr = (color << 8) | 200;
				video->setCharAtPos(attr,rect->x,rect->y+rect->h);

				attr = (color << 8) | 188;
				video->setCharAtPos(attr,rect->x+rect->w+5,rect->y+rect->h);

				attr = (color << 8) | 187;
				video->setCharAtPos(attr,rect->x+rect->w+5,rect->y);

				attr = (color << 8) | 'o';
				int x1,y1;
				for (y1=1;y1<rect->h;y1++) {
					for (x1=1;x1<rect->w+5;x1++) {
						video->setCharAtPos(attr,
						rect->x+x1 ,
						rect->y+y1 );
					}	x1=0;
				}
			}

			void TWindow::handleEvent(class TVideo * video)
			{
				draw();
				//video->buffer[(80*5)+5] = 0x0f05;
				//memcpy(VideoMem,video->buffer,80*25*2*2);
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros