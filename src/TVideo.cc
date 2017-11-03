#include <types.hpp>
#include <stdarg.h>

#include <TVideo.hpp>
#include <TStream.hpp>

#include <pc.h>

extern "C" void * malloc(size_t);
extern "C" void * memset(void*,void*,size_t);
extern "C" void * memcpy(void*,void*,size_t);
namespace ros {
	namespace tui {
		namespace crt
		{
			extern unsigned short offscr[];
			TVideo::TVideo()
			{
				Xpos = 0;
				Ypos = 0;

				VideoMem = (unsigned short*) 0xb8000;
			}

			void TVideo::init(void)
			{
				clrscr();
			}
			void TVideo::draw(void)
			{
				memcpy(VideoMem,buffer,80*25*2*2);
			}

			void TVideo::clrscr(void)
			{
				uint8_t x;
				uint8_t y;

				Xpos = 0;
				Ypos = 0;

				for (y = 0; y < 25; y++) {
					for (x = 0; x < 80; x++) {
						setCharAtPos(0xb0b0,x,y);
					}	x = 0;
				}
			}

			void TVideo::outint(int n)
			{
			    char back[10];
			    char *ph  = back;
			    int h     = 0;

			    if ( !n    ) { return; }
			    if ( n < 0 ) { n =- n; }

			    while (n) {
			        h = n % 10;
			        n = n / 10;
			        *ph++ = (char)('0' + h);
			    }

			    while (ph > back)
			    setChar(*(--ph));

			    return;
			}
			void TVideo::writeString(TString s)
			{
				//writeString(s.c_str());
			}
			void TVideo::writeString(char *str)
			{
			    uint16_t  ch;
			    for (int c = 0; c < strlen(str); c++)
			    {
			    	ch = ((uint8_t)fg_color << 8) | str[c];
			    	buffer[(Ypos*80)+Xpos] = ch;
			    	++Xpos;
			    }
			}
			void TVideo::setString(char *txt, ...)
			{
			    va_list args;

			    char *pstr;
			    char *pt  ;

			    int   ch   =   0 ;
			    int   n    =   0 ;

			    pstr = (char*)malloc(2024);
			    pt   = (char*)malloc(2024);

			    va_start(args, txt);
			    for (pt = txt; *pt; pt++) {
			        if (*pt == '\t') {
			            int c=0;
			            for (c=0; c<8;c++)
			            setChar(' ');
			        }
			        else if (*pt == '\0') {
			            break;
			        }
				    else if (*pt == '%')
			        {
				        switch (*(++pt)) {
				            case 'c':
					        {
					        ch = (char) va_arg(args, int);
					        pstr[0] = ch;
					        pstr[1] = '\0';
					        writeString(pstr);
					        break;
					        }
				        case 's':
					        {
					        pstr = (char*) va_arg(args, char*);
					        writeString(pstr);
					        break;
					        }
				        case 'd':
					        {
					        n = (int) va_arg(args, int);
					        outint(n);
					        break;
					        }
				        case 0: { return; }
				        default:{
					        pstr[0] = '%';
					        pstr[1] = *pt;
					        pstr[2] = '\0';
					        writeString(pstr);
					        }
			            }
			    	}
			        else {
			            setChar(*pt);
			            continue;
			        }
			    }
			    va_end(args);

			    delete pstr;
			    delete pt;

			    return;
			}
			void TVideo::setCursorAtPos(uint16_t col, uint16_t row)
			{
			    unsigned short position = (row*80) + col;

			    // cursor HIGH port to vga INDEX register
			    outportb(0x3D4, 0x0E);
			    outportb(0x3D5, (unsigned char)((position>>8)&0xFF));

			    // cursor LOW port to vga INDEX register
			    outportb(0x3D4, 0x0F);
			    outportb(0x3D5, (unsigned char)(position&0xFF));

			    Xpos = col;
    			Ypos = row;
			}

			void TVideo::setChar(uint8_t c)
			{
			    buffer[(Ypos*80) + Xpos] = (14 << 8) | c;
			    ++Xpos;
			}

			uint8_t TVideo::getColor(void) {
				return fg_color;
			}

			uint16_t * TVideo::getBuffer(void) { return buffer; }
			void       TVideo::setBuffer(uint16_t *ptr)
			{
				//buffer = ptr;
			}

			void TVideo::setColor(uint8_t fg)				{ fg_color = fg; }
			void TVideo::setColor(uint8_t fg, uint8_t bg)	{ fg_color = fg; bg_color = bg; }

			void TVideo::setForegroundColor(uint8_t fg) { fg_color = fg; }
			void TVideo::setBackgroundColor(uint8_t bg) { bg_color = bg; }

			uint8_t TVideo::getForegroundColor(void) { return fg_color; }
			uint8_t TVideo::getBackgroundColor(void) { return bg_color; }

			void TVideo::setCharAtPos(unsigned short c, uint16_t x, uint16_t y)
			{
				Xpos = x;
				Ypos = y;

				setCursorAtPos(x,y);
				buffer[(80*Ypos)+Xpos] = c;
			}
			uint16_t TVideo::getCharAtPos(uint8_t x, uint8_t y)
			{
    			setCursorAtPos(x,y);
    			return buffer[(y*80)+x];
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros