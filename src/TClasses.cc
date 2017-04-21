#include <typeinfo>
#include "TObject.h"

static std::map<const type_info*, std::string> ClassTable;

TClass::TClass() { }

bool TClass::RegisterClass(type_info *t, TString _name) {
    if (name == "TObject")
    return;
    
    ClassTable[&typeid(t)] = t.name();
    name = _name;
    
    cout << ClassTable[&typeid(t)] << "  :  " << value.value << "\n";
}

bool TClass::RegisterClass(type_info *t) {
    TString s = typeid(t).name();
    if (s == "TObject")  return true;
    
    RegisterClass(t,s);
    return true;
}

bool TClass::RegisterClass(class TClass _Sender)
{
    RegisterClass(_Sender,typeid(_Sender).name();
    return true;
}

TString TClass::ClassName()
{
    return name;
}
