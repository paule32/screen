#ifndef _TVIDEO_H_
#define _TVIDEO_H_

#include <types.hpp>
#include <TObject.h>
#include <string.hpp>

extern "C" void free(void*);
namespace ros {
	namespace tui {
		namespace crt {
			class TVideo: public TObject
			{
			public:
				explicit TVideo();

				uint16_t * VideoMem;
				uint16_t   buffer[80*25*2*2];
				uint16_t   cursor_buffer;

				void	 clrscr(void);

				uint16_t  getCharAtPos(uint8_t,uint8_t);
				void     setCharAtPos(unsigned short,uint16_t,uint16_t);

				void     setChar(uint8_t);

				uint8_t  getColor(void);

				void     setColor (uint8_t);
				void	 setColor (uint8_t,uint8_t);

				void	 setString(char*, ...);
				void     setCursorAtPos(uint16_t,uint16_t);

				void	 setForegroundColor(uint8_t);
				void	 setBackgroundColor(uint8_t);

				uint8_t  getForegroundColor(void);
				uint8_t  getBackgroundColor(void);

				uint16_t * getBuffer(void);
				void       setBuffer(uint16_t*);

				void	 writeString(char*);
				void	 writeString(TString);

				void init(void);
				void draw(void);

			private:
				void	 outint(int);

			public:
				uint8_t 	 Xpos;
				uint8_t      Ypos;

			public:
				uint8_t    fg_color;
				uint8_t    bg_color;

			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header