#include "TApplication.h"
using namespace std;

main(int argc, char **argv)
{
    TApplication app;
       
    try {
        std::ofstream out;
        out.open("a.out" ,ios::out);

        app.init(argc,argv);
        app.run();
        
        out << app;
        out.close();
    }
    catch (...) {
    }
}

