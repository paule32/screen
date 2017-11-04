#include <new.hpp>
#include <TStack.hpp>
#include <TWindow.hpp>

namespace ros {
	namespace tui {
		namespace crt {
			#define SIZE 2048
			TStack::TStack(void)
			{
				tos = 0; // initialize top of stack
				stack_array = (struct StackArray*) malloc(sizeof(StackArray)*SIZE);
			}
			TStack::~TStack()
			{
				delete stack_array;
			}
			int TStack::isEmpty(void)
			{
				return (tos == 0 ? 1 : 0);
			}
			int TStack::isFull(void)
			{
				return (tos == SIZE ? 1 : 0);
			}
			void TStack::push(int i)
			{
				if (!isFull())
				{
					stack_array[tos].type = TOS_TYPE_INT;
					stack_array[tos].value_int = i;
					++tos;
				}
				#if 0
				else {
					new TException((char*)"Stack overflow error!");
				}
				#endif
			}
			void TStack::push(TWindow *w)
			{
				if (!isFull())
				{
					stack_array[tos].type = TOS_TYPE_WINDOW;
					stack_array[tos].value_window = w;
					++tos;
				}
				#if 0
				else {
					new TException((char*)"Stack overflow error!");
				}
				#endif
			}
		}	// namespace ros::tui::crt
	}		// namespace ros::tui
}			// namespace ros