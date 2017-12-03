#include <types.hpp>
#include <TStream.hpp>
#include <string.hpp>

extern "C" int atexit() {
	return 0;
}

namespace ros {
	namespace tui {
		namespace crt {
			class TStream cout;

			TStream::TStream()
			{

			}

			TStream& TStream::operator << (const ros::TString s)
			{
				the_string = (char*) malloc(strlen(s.the_string));
				the_string = s.the_string;
				setString((char*)"%s",the_string);
				return *this;
			}
			TStream& TStream::operator << (char *rhs)
			{
				the_string = (char*) malloc(strlen(rhs));
				the_string = rhs;
				setString((char*)"%s",the_string);
				return *this;
			}
			TStream& TStream::operator << (char rhs)
			{
				setColor(14);
				setChar(rhs);
				return *this;
			}

			TStream& TStream::operator << (const char* rhs)
			{
				setColor(15);
				setString((char*)"%s", rhs);
				return *this;
			}
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros