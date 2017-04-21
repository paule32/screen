#include "TApplication.h"
#include <string>
#include <typeinfo>
#include <map>

using namespace std;

extern std::map<const type_info*, std::string> Classes;

// TApplication
TApplication::TApplication(void)
{
//    std::cout << typeid(this) << std::endl;
    
//    ClassName = "TApplication";
//    desktop = new TDesktop;

Classes[&typeid(TApplication)] = "TApplication";
std::cout << "start ..." << "\n";
}

void TApplication::init(int argc, char **argv)
{
}

void TApplication::run(void)
{
}

// TApplication stream ... 
std::ostream & operator << (std::ostream &out, TApplication &obj)
{
//    out << obj.ClassName;
    
//    obj.ident += "  ";
    
//    out << obj.ClassName;
//    out << ":" << std::endl << obj.ident
//        << "{" << std::endl ;
        
    return out;
}
std::istream & operator >> (std::istream &in, TApplication &obj)
{
//    in >> obj.ClassName;    
    return in;
}
