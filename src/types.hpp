#ifndef ROS_TYPES_H_
#define ROS_TYPES_H_

typedef	unsigned int         size_t;
typedef unsigned char       uint8_t;
typedef unsigned short     uint16_t;
typedef unsigned long      uint32_t;
typedef unsigned long long uint64_t;

typedef unsigned char          BYTE; 
typedef unsigned short         WORD;
typedef unsigned int          DWORD;
typedef uint64_t          ULONGLONG;

#ifndef NULL
#define NULL 0
#endif

#ifdef __cplusplus
extern "C" {

extern void * malloc(size_t);
extern void * memcpy(void*,void*,size_t);
extern void   memset(void*,void*,size_t);

extern void initPS2(void);
extern void mouse_handler(void);

extern short int _mouse_x;
extern short int _mouse_y;

extern char buttons; 

};
#endif  // __cplusplus
#endif	// header