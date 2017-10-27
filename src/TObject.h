#ifndef TOBJECT_H_
#define TOBJECT_H_

#include <string.hpp>

class TObject
{
//    friend std::ostream& operator << (std::ostream &out, TObject &obj);
//    friend std::istream& operator >> (std::istream &out, TObject &obj);
    
public:
    explicit TObject();
    //class TClass Owner;
    //class TClass Sender;

    class ros::string ClassName;
};
#endif
