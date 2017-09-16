#ifndef TAPPLICATION_H_
#define TAPPLICATION_H_

#include <THeaders.h>

class TApplication: public TObject
{
    friend std::ostream& operator << (std::ostream &out, TApplication &obj);
    friend std::istream& operator >> (std::istream &out, TApplication &obj);
    
public:
    class TDesktop * desktop;
    
    explicit TApplication(void);
    
    void init(int,char**);
    void run(void);
};
#endif
