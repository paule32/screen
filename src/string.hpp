#ifndef ROS_string_H_
#define ROS_string_H_

#include <THeaders.h>

#ifdef __cplusplus
extern "C" {
#endif
/** copy source string @src to destination string @dst */
extern char *strcpy(char*dst,char*src);
/** returns the length of string str */
extern int strlen(char* str);
#ifdef __cplusplus
};

/** Extended string class */
class string
{
public:
	/** Plain string constructor that
	 * constructs empty string object
	 */
	explicit string(void);
	explicit string(const string&);

	/** Destructor: destroy any string object */
	~string();

	/** assings string to class object */
	string& operator = (const char*);
	string& operator = (const string&);

private:
	char *the_string;
};
#endif // __cplusplus
#endif // header