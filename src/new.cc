#include <new.hpp>

/** this operator allocates size memory for C++ objects */
void * operator new(size_t size)
{
	return malloc(size);
}

/** this operator allocates block of memory for C++ objects */
void * operator new[](size_t size)
{
	return malloc(size);
}

/** this operator delete a buffer / object, created with new */
void operator delete(void * ptr)
{
	free(ptr);
}