#include <THeaders.h>

namespace ros {
TApplication::TApplication(void)
{
	ClassName = (char*)"TApplication";
	deskTop = new TDesktop;
}

void TApplication::init(void)
{
}

void TApplication::run(void)
{
}

} // namespace