#include <TApplication.hpp>
using namespace ros::tui::crt;

extern "C"
void switch2cpp(void)
{
	TApplication app;
	app.init();
	app.exec();
}
