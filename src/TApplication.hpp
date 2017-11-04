#ifndef TAPPLICATION_H_
#define TAPPLICATION_H_

#include <TObject.h>
#include <TVideo.hpp>
#include <TDesktop.hpp>
#include <TMenuBar.hpp>
#include <TStatusBar.hpp>
#include <TEvent.hpp>
#include <TWindow.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			/* \class TApplication
			 * \brief A fundamental class for applications.
			 * 		  You can define the types TUT, and GUI.
			 * 		  
			 * \example doc_example_1.cc
			 * This is an example of how to use  the TApplication class.
			 * More details about this example.
			 */
			class TApplication
			{
			public:
				/** constructor for TApplication */
				explicit TApplication(void);
			    
			    void init(void);
			    void exec(void);

			protected:
				/** the desktop object for the application */
			    class TDeskTop   * deskTop;
			    class TMenuBar   * menuBar;
			    class TStatusBar * statusBar;

			    class TVideo * video;
			    class TMouse * mouse;

			    void handleEvent(void);
			};
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros
#endif		// header
