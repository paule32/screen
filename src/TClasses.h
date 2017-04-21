#ifndef TCLASSES_H_
#define TCLASSES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <map>

using namespace std;
class TString;

class TClass {
public:
    explicit TClass();
    
    bool RegisterClass(std::type_info *t,TString _name);
    bool RegisterClass(std::type_info *t);
    bool RegisterClass(class TClass _Sender);
    
    TString ClassName();
    
private:
    std::string name;
};

#ifndef TOBJECT_H_
#include "TObject.h"
#endif

#ifndef TSTRING_H_
#include "TString.h"
#endif

#endif
