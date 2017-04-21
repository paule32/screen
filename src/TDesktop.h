#ifndef TDESKTOP_H_
#define TDESKTOP_H_

#include "TObject.h"

class TDesktop: public TObject
{
    friend std::ostream& operator << (std::ostream &out, TDesktop &obj);
    friend std::istream& operator >> (std::istream &out, TDesktop &obj);
    
public:
    explicit TDesktop();
    ~TDesktop();
};
#endif
