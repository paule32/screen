#ifndef ROS_TYPES_H_
#define ROS_TYPES_H_

typedef	unsigned int       size_t;
typedef unsigned char      uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned long      uint32_t;
typedef unsigned long long uint64_t;

#ifndef NULL
#define NULL 0
#endif

#ifdef __cplusplus
extern "C" {

extern void * malloc(size_t);
extern void * memcpy(void*,void*,size_t);
};
#endif  // __cplusplus
#endif	// header