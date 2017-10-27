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
#endif

#ifdef __cplusplus
extern void * operator new[](size_t size);
extern void * operator new ( size_t size);

extern void operator delete( void * ptr );

namespace ros {
#include <new.hpp>
#include <string.hpp>
	
#include <TObject.h>
#include <TClasses.h>
#include <TDesktop.h>
#include <TApplication.hpp>
#include <TMenuBar.hpp>

} // namespace

#endif
#endif
