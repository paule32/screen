#ifndef TOBJECT_H_
#define TOBJECT_H_

#include <string.hpp>

namespace ros {
class string;

class TObject
{
//    friend std::ostream& operator << (std::ostream &out, TObject &obj);
//    friend std::istream& operator >> (std::istream &out, TObject &obj);
    
public:
    explicit TObject(void);
    //class TClass Owner;
    //class TClass Sender;

    class TString ClassName;
};
}  // namespace ros
#endif
