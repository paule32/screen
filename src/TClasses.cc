#include <typeinfo>
#include "TObject.h"

static std::map<const type_info*, std::string> ClassTable;

TClass::TClass() { }

bool TClass::RegisterClass(type_info *t, TString name) {
    if (name == "TObject")
    return;
    
    ClassTable[&typeid(t)] = t.name();
    value = name;
    
    cout << ClassTable[&typeid(t)] << "  :  " << value.value << "\n";
}

bool TClass::RegisterClass(type_info *t) {
    TString s = typeid(t).name();
    if (s == "TObject")  return ;
    
    RegisterClass(t,s);
}

TString TClass::ClassName()
{
    return this->value();
}
