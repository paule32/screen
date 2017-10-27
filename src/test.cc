#include <THeaders.h>
using namespace ros;

extern "C" void switch2cpp(void);
void switch2cpp(void)
{
	class ros::TApplication app;
	app.init();
}
