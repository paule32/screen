#ifndef _TEXCEPTION_H__
#define _TEXCEPTION_H__

#include <types.hpp>
#include <new.hpp>

extern "C" {
extern void __gxx_personality_sj0(void);
};
namespace ros {
	namespace tui {
		namespace crt {
			class TException
			{
			public:
				TException(char*);
				TException();

				char *what;
			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif