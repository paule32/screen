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


TString & TString::operator = (TString &rhs)
{
    value = rhs.value;
    return *this;
}

bool TString::operator == (TString &rhs)
{
    if (value == rhs.value)
    return true; else
    return false;
}

bool TString::operator == (TString rhs)
{
    return value == rhs.value;
}

bool TString::isEmpty()
{
    if (value.size() < 1)
    return true; else
    return false;
}
