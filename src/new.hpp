// -------------------------------------
// ROS - ReactOS STL
// (c) 2017 Jens Kallup - paule32
// -------------------------------------
#ifndef ROS_NEWDELETE_H_
#define ROS_NEWDELETE_H_

#include <types.hpp>

extern "C" {
extern void *malloc(size_t size);
extern void    free(void * ptr);
};

#endif