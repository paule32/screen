#ifndef TDESKTOP_H_
#define TDESKTOP_H_

#include <types.hpp>
#include <TObject.h>
<<<<<<< HEAD
#include <TMenuBar.hpp>
#include <TStatusBar.hpp>
=======
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290

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
<<<<<<< HEAD
			    explicit TDeskTop(TVideo *_video);
=======
			    explicit TDeskTop();
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
			    ~TDeskTop();

			    void init();
			    void draw();

			    TVideo *video;
<<<<<<< HEAD
			    TMenuBar *menuBar;
			    TStatusBar *statusBar;
=======
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header
