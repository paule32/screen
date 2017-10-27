#include <THeaders.h>

static std::map<const type_info*, std::string> ClassTable;

TClass::TClass() { }

bool TClass::RegisterClass(type_info *t, std::string _name) {
#if 0
    if (ClassName == "TObject")
    return true;

    ClassTable[&typeid(t)] = t->name();
    ClassName = _name;

    cout << ClassTable[&typeid(t)] << "  :  " << ClassName << "\n";
#endif
    return true;
}

bool TClass::RegisterClass(type_info *t) {
#if 0
    std::string s(typeid(t).name());
    if (s == "TObject")  return true;

    RegisterClass(t,s);
#endif
    return true;
}

