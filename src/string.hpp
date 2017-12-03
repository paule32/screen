#ifndef ROS_string_H_
#define ROS_string_H_

//#include <THeaders.h>

#ifdef __cplusplus
extern "C" {
#endif
/** copy source string @src to destination string @dst */
extern char *strcpy(char*dst,char*src);
/** returns the length of string str */
extern int strlen(char* str);
#ifdef __cplusplus
};
namespace ros {
/** Extended string class */
class TString
{
public:
	/** Plain string constructor that
	 * constructs empty string object
	 */
	TString(void);
	TString(char*);
	//TString(const char*);
	TString(const ros::TString&);
	TString(      ros::TString&);

	/** Destructor: destroy any string object */
	~TString();

	/** assings string to class object */
	TString& operator = (char*);

	TString& operator = (TString);
	TString& operator = (TString&);

	char* center(void);

	void setText(char *);

	char *c_str(void);
	char *the_string;
};
}      // namespace ros
#endif // __cplusplus
#endif // header