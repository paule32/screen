#ifndef TMENUBAR_H_
#define TMENUBAR_H_

#include <TObject.h>

namespace ros {
	namespace tui {
		class TMenuBar: public TObject
		{
		public:
			explicit TMenuBar();
			~TMenuBar();

		protected:
			//virtual void draw();
		};
	}	// namespace tui
}		// namespace ros
#endif