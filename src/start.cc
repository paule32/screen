#include "TApplication.h"

main(int argc, char **argv)
{
    TApplication app;

    try {
        app.init(argc,argv);
        app.run();
    }
    catch (...) {
    }
}

