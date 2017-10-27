#ifndef THEADERS_H_
#define THEADERS_H_

typedef	unsigned int	     size_t;
typedef unsigned char       uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned long      uint32_t;
typedef unsigned long long uint64_t;

#ifdef __cplusplus
extern "C" {
#endif
void     *malloc(size_t);				//< The standard function.
void     *realloc(void *, size_t);		//< The standard function.
void     *calloc(size_t, size_t);		//< The standard function.

void free(void *); //< The standard function.

#ifdef __cplusplus
};

extern void * operator new[](size_t size);
extern void * operator new ( size_t size);

extern void operator delete( void * ptr );

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

/*! \mainpage ReactOS fork \@paule32 (c) 2017
 *	\section intro_sec Introduction
 *	
 *	Introduction
 *	The ReactOS Project aim's to be a Free Windows compatible OS.
 *	You can support the Project by donatation.
 */
namespace ros {
#include <new.hpp>
#include <string.hpp>

#include <TObject.h>
#include <TDesktop.hpp>
#include <TApplication.hpp>
#include <TMenuBar.hpp>

} // namespace
#endif // __cplusplus
#endif // header
