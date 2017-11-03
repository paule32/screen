#ifndef TDESKTOP_H_
#define TDESKTOP_H_

#include <types.hpp>
#include <TObject.h>

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
			    explicit TDeskTop();
			    ~TDeskTop();

			    void init();
			    void draw();

			    TVideo *video;
			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header
