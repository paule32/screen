#ifndef TCLASSES_H_
#define TCLASSES_H_

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <typeinfo>
#include <vector>
#include <map>

#ifndef TOBJECT_H_
#include "TObject.h"
#endif

#include "TString.h"

class TClass {
public:
    explicit TClass();
    
    bool RegisterClass(std::type_info *t,TString name);
    bool RegisterClass(std::type_info *t);
    
    TString ClassName();
};

#endif
