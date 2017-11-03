#include <TVideo.hpp>
#include <TDesktop.hpp>

namespace ros {
    namespace tui {
        namespace crt {
            extern unsigned short offscr[];

            TColor::TColor() { }

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

            TDeskTop::TDeskTop()
            {
                video = new TVideo;
            }

            TDeskTop::~TDeskTop()
            {
            }

            void TDeskTop::init()
            {
                unsigned short cnty = 0;
                unsigned short cntx = 0;

                //video->setPattern(0xb0);
                //video->setColor  (0xb0);

                for (cnty=0;cnty<=25;cnty++) {
                    for (cntx=0;cntx<=80;cntx++) {
                        video->buffer[ (cnty*80) + cntx] = 0xb0b0; //(getColor() << 8) | getPattern();
                    }
                    cntx = 0;
                }
            }

            void TDeskTop::draw()
            {
                memcpy(offscr,video->buffer,80*25*2*2);
            }
        }   // namespace ros::tui::crt
    }       // namespace ros::tui
}           // namespace ros