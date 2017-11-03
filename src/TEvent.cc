#include <new.hpp>
#include <TEvent.hpp>

extern "C" unsigned char buttons; 
namespace ros {
	namespace tui {
		namespace crt {

			TEvent::TEvent()
			{
			}
			TEvent::~TEvent()
			{

			}
			TEvent * TEvent::exec(TMouse* mevt)
			{
				static unsigned short old_mx = 0;
			    static unsigned short old_my = 0;

			    mouse.posX = 0;
			    mouse.posY = 0;

			    _mouse_x = 0;
    			_mouse_y = 0;

    			mouse_handler();
    			mouse.button = buttons;

		        if (old_mx > 79) { old_mx = 79; } else
		        if (old_mx <= 0) { old_mx =  0; }

		        if (old_my > 24) { old_my = 24; } else
		        if (old_my <= 0) { old_my =  0; }

		        if (_mouse_x > 79) { _mouse_x = 79; } else
		        if (_mouse_x <= 0) { _mouse_x =  0; }

		        if (_mouse_y > 24) { _mouse_y = 24; } else
		        if (_mouse_y <= 0) { _mouse_y =  0; }

		        if (_mouse_x > old_mx) { mouse.posX = _mouse_x; } else
		        if (_mouse_x < old_mx) { mouse.posX = old_mx;   }


		        if (_mouse_y > old_my) { mouse.posY = _mouse_y; } else
		        if (_mouse_y < old_my) { mouse.posY = old_my;   }

		        if (mouse.posX > 79) { mouse.posX = _mouse_x = 79; } else
		        if (mouse.posX <= 0) { mouse.posX = _mouse_x =  0; }

		        if (mouse.posY > 24) { mouse.posY = _mouse_y = 24; } else
		        if (mouse.posY <= 0) { mouse.posY = _mouse_y =  0; }

		        mouse.posX = _mouse_x;
		        mouse.posY = _mouse_y;

		        mevt->video->VideoMem[(80       *
				mevt->event->mouse.posY) +
				mevt->event->mouse.posX] = 0xe203;

				return this;
			}
		}
	}
}