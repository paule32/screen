#ifndef TCLASSES_H_
#define TCLASSES_H_

#include <TString.h>

class TClass {
public:
    explicit TClass();
    
    bool RegisterClass(std::type_info *t,class TString _name);
    bool RegisterClass(std::type_info *t);
    bool RegisterClass(class TClass _Sender);
    
    class TString ClassName;
    
private:
    std::string name;
};

#endif
