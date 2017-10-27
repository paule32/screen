#include <THeaders.h>

namespace ros {
TApplication::TApplication(void)
{
	ClassName = (char*)"TApplication";
	deskTop = new TDeskTop;
}

void TApplication::init(void)
{
}

void TApplication::run(void)
{
}

}