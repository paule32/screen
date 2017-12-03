#include <types.hpp>
#include <string.hpp>

namespace ros {
TString::TString(void)
{
	the_string = (char*) malloc(100);
}

TString::~TString()
{
	delete the_string;
}

TString::TString(TString &str)
{
	the_string = (char*) malloc(strlen(str.the_string));
	the_string = str.the_string;
}

TString::TString(char *s)
{
	the_string = (char*) malloc(strlen(s));
	strcpy(the_string,s);
}

TString& TString::operator = (char *str)
{
	the_string  = new char[strlen(str)];
	strcpy(the_string, str);
	return *this;
}

TString& TString::operator = (TString &str)
{
	the_string = new char[strlen(str.the_string)];
	strcpy(the_string,str.the_string);
	return *this;
}

void TString::setText(char *s)
{
	if (!s)
		s = (char*) malloc(100);
	if (!the_string)
		the_string = (char*) malloc(strlen(s));
		the_string = s;
}

char* TString::center(void)
{
	int len = 80 / 2;
	int pos = len + (strlen(the_string) / 2);
	int i;

	char txt[100];

	for (i=0;i<=pos+1;i++)
	txt[i] = ' ';

	for (i=0;i<=strlen(the_string);i++)
	txt[pos+i] = the_string[i];
	
    int l0 = strlen(txt);
    int l1 = 100 - (l0-2);

	for (i=0;i<=l1+1;i++)
	txt[l0+i] = ' ';

	the_string = (char*) malloc(strlen(txt));
	strcpy(the_string,txt);
	return the_string;
}

char* TString::c_str(void) {
	return the_string;
}

}