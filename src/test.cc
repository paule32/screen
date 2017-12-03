#include <TApplication.hpp>
using namespace ros::tui::crt;

class MyApp: public TApplication {
public:
    explicit MyApp(TVideo *video);
    ~MyApp();
private:
	class TRect rect;
};

MyApp:: MyApp(TVideo *_video)
    : TApplication(_video)  {
    video = _video;
}

MyApp::~MyApp() { }

extern void format_volume();

extern "C"
void switch2cpp(void)
{
    TVideo      * video = new TVideo;
	class MyApp * app   = new MyApp(video);
    class TRect rect;

    //format_volume();

	rect.x =  5; rect.y = 10;
	rect.w = 20; rect.h = 5;
	
	windows[0] = new TWindow(video, &rect);
	windows[0]->show();

	app->init();
	app->exec();

    delete app;
}

