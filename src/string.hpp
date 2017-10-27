#ifndef ROS_string_H_
#define ROS_string_H_

extern "C" {
/** copy source string @src to destination string @dst */
extern char *strcpy(char*dst,char*src);
/** returns the length of string str */
extern int strlen(char* str);
};

/**
 * \namespace ros
 * ReactOS STL namespace<br>
 * It is a small implementation of the standard template library
 * provided by huge compiler system's.
 * 
 * Please don't cry - not all STL elements are ported over for
 * ReactOS.
 * 
 * The idea was, to simply have fast running, and stable Windows
 * operation system.
 */
namespace ros {
/*! \mainpage ReactOS fork \@paule32 (c) 2017
 *	\section intro_sec Introduction
 *	
 *	Introduction
 *	The ReactOS Project aim's to be a Free Windows compatible OS.
 *	You can support the Project by donatation.
 */

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

} // namespace
#endif