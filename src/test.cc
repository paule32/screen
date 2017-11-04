#include <TApplication.hpp>
using namespace ros::tui::crt;

extern "C"
void switch2cpp(void)
{
	class TApplication app;
	class TRect rect;

	rect.x =  5; rect.y = 10;
	rect.w = 20; rect.h = 5;

	class TWindow *win1 = new TWindow(&rect);
	win1->show();

	app.init();
	app.exec();
}
