#ifndef _TSTACK_H_
#define _TSTACK_H_

#include <types.hpp>
#include <TVideo.hpp>
#include <TRect.hpp>
#include <TWindow.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			enum tos_type {
				TOS_TYPE_INT = 1,
				TOS_TYPE_WINDOW
			};
			struct StackArray {
				tos_type        type;
				int             value_int;
				class TWindow * value_window;
			} StackArray;
			class TStack {
			public:
				TStack(void);
				~TStack();

				int isEmpty(void);
				int isFull(void);

				void push(int);
				void push(TWindow*);

				struct StackArray * stack_array;
				int tos;
			};
		}	// namespace ros::tui:crt
	}		// namespace ros::tui
}			// namespace ros
#endif