#include "TClasses.h"

TObject::TObject()
{
    if (Owner().ClassName() == TString("TObject"))
    return;
    
    TClass::RegisterClass(Sender());
}
