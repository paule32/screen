#include <THeaders.h>
using namespace ros;

extern "C" void switch2cpp(void)
{
	TApplication app;
	app.init();
}
