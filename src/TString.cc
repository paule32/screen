#include <THeaders.h>

// TString stream:
std::ostream& operator << (std::ostream &out, TString obj)
{
//    out << obj.ClassName;
    return out;
}
std::ostream& operator << (std::ostream &out, TString &obj)
{
//    out << obj.ClassName;
    return out;
}
std::istream & operator >> (std::istream &in, TString obj)
{
//    in >> obj.ClassName;
    return in;
}
std::istream & operator >> (std::istream &in, TString &obj)
{
//    in >> obj.ClassName;
    return in;
}

TString::TString(void)
{
//    ClassName = "TString";
}

TString::TString(char *txt)
{
//     ClassName = "TString";
}


bool TString::isEmpty()
{
    if (value.size() < 1)
    return true; else
    return false;
}
