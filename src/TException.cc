#include <new.hpp>
#include <TException.hpp>

extern "C" {
extern int  strlen(char*);
extern void strcpy(char*,char*);

void __gxx_personality_sj0(void) {}
}
namespace ros {
	namespace tui {
		namespace crt {
			TException::TException()
			{
				new TException((char*)"Error occur.");
			}
			TException::TException(char* msg)
			{
				what = new char[strlen(msg)];
				strcpy(what,msg);
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros