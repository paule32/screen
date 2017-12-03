#include <TApplication.hpp>
using namespace ros::tui::crt;
<<<<<<< HEAD

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
=======
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290

extern "C"
void switch2cpp(void)
{
<<<<<<< HEAD
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
=======
	class TApplication app;
	class TRect rect;

	rect.x =  5; rect.y = 10;
	rect.w = 20; rect.h = 5;

	class TWindow *win1 = new TWindow(&rect);
	win1->show();

	app.init();
	app.exec();
>>>>>>> 31ea98d2452f2959f37d947255dda72fc20e9290
}

