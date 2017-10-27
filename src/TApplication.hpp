#ifndef TAPPLICATION_H_
#define TAPPLICATION_H_

#include <THeaders.h>

/* \class TApplication
 * \brief A fundamental class for applications.
 * 		  You can define the types TUT, and GUI.
 * 		  
 * \example doc_example_1.cc
 * This is an example of how to use  the TApplication class.
 * More details about this example.
 */
class TApplication: public TObject
{
public:
	/** constructor for TApplication */
    explicit TApplication(void);
    
    void init(void);
    void run(void);

protected:
	/** the desktop object for the application */
    class TDeskTop  * deskTop;
    
};
#endif