#include <THeaders.h>

TDesktop::TDesktop()
{
    //this->ClassName = "TDesktop";
}

TDesktop::~TDesktop()
{
}

// TDesktop stream ... 
std::ostream & operator << (std::ostream &out, class TDesktop &obj)
{
    //obj.ident += "  ";
    
    //out << obj.ClassName;
    //out << ":" << std::endl << obj.ident
    //    << "{" << std::endl ;
    return out;
}
std::istream & operator >> (std::istream &in, class TDesktop &obj)
{
    //in >> obj.ClassName;    
    return in;
}
