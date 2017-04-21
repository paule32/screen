#include "TClasses.h"

TString TObject::ClassName()
{
    return Owner().ClassName();
}

TObject::TObject()
{
    if (Owner->ClassName().value == "TObject")
    return;
    
    Sender->RegisterClass(this);
//    Classes[&typeid(TObject)] = "TObject";
//    cout << Classes[&typeid(TObject)] << "\n";
}
