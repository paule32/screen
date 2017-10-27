#include <THeaders.h>

namespace ros {
string::string(void)
{
	the_string = new char[100];
}

string::~string()
{
	delete the_string;
}

string& string::operator = (const string &str)
{
	the_string = new char[strlen(str.the_string)];
	strcpy(the_string,str.the_string);
	return *this;
}
}  // namespace