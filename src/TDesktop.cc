#include <TVideo.hpp>
#include <TDesktop.hpp>
#include <TMenuBar.hpp>

namespace ros {
    namespace tui {
        namespace crt {
            extern unsigned short offscr[];
<<<<<<< HEAD
            extern unsigned short *bupScreen;
            extern unsigned short * VideoMem;

            TColor::TColor() {
            }
=======

            TColor::TColor() { }
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290

            uint8_t TColor::getColor(void)
            {
                return the_color;
            }
            void TColor::setColor(uint8_t c)
            {
                the_color = c;
            }

            TPattern::TPattern()
            {
                setPattern(0xb2);
                setColor(0xb0);
            }

            uint8_t TPattern::getPattern(void)
            {
                return pattern;
            }

            void TPattern::setPattern(uint8_t p)
            {
                pattern = p;
            }

<<<<<<< HEAD
            TDeskTop::TDeskTop(TVideo *_video)
            {
        		menuBar = new TMenuBar(_video);
				menuBar->init();
				
				statusBar = new TStatusBar(_video);
				statusBar->init();
				
				video = _video;
=======
            TDeskTop::TDeskTop()
            {
                video = new TVideo;
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
            }

            TDeskTop::~TDeskTop()
            {
            }

            void TDeskTop::init()
            {
                unsigned short cnty = 0;
                unsigned short cntx = 0;

<<<<<<< HEAD
                for (cnty=0;cnty<25;cnty++) {
                    for (cntx=0;cntx<80;cntx++) {
=======
                //video->setPattern(0xb0);
                //video->setColor  (0xb0);

                for (cnty=0;cnty<=25;cnty++) {
                    for (cntx=0;cntx<=80;cntx++) {
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
                        video->buffer[ (cnty*80) + cntx] = 0xb0b0; //(getColor() << 8) | getPattern();
                    }
                    cntx = 0;
                }
            }

            void TDeskTop::draw()
            {
<<<<<<< HEAD
                menuBar  ->draw();
				statusBar->draw();
				
				memcpy(bupScreen,video->buffer,80*25*2*2);
                memcpy(offscr,bupScreen,80*25*2*2);
                memcpy(VideoMem,bupScreen,80*25*2*2);
            }
        }   // namespace ros::tui::crt
    }       // namespace ros::tui
}           // namespace ros
=======
                memcpy(offscr,video->buffer,80*25*2*2);
            }
        }   // namespace ros::tui::crt
    }       // namespace ros::tui
}           // namespace ros
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
