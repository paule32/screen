#ifndef TDESKTOP_H_
#define TDESKTOP_H_

#include <types.hpp>
#include <TObject.h>
#include <TMenuBar.hpp>
#include <TStatusBar.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			class TColor: public TVideo
			{
			public:
				explicit  TColor(void);
				uint8_t getColor(void);
				void    setColor(uint8_t);

			private:
				uint8_t the_color;
			};

			class TPattern: public TColor
			{
			public:
				explicit TPattern(void);
				uint8_t   getPattern(void);
				void      setPattern(uint8_t);

			private:
				uint8_t pattern;
			};

			class TDeskTop
			{    
			public:
			    explicit TDeskTop(TVideo *_video);
			    ~TDeskTop();

			    void init();
			    void draw();

			    TVideo *video;
			    TMenuBar *menuBar;
			    TStatusBar *statusBar;
			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header
