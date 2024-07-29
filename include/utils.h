#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <errno.h>

//user optional definitions
// #define CHECK_UNREACHABLE //puts an assert instead of ub 


#if defined(CHECK_UNREACHABLE)

#ifndef __cplusplus
#include <assert.h>
#else
#include <cassert>
#endif //__cplusplus

#define UNREACHABLE() assert(0 && "Unreachable code reached")

#define ASSERT(x) assert(x) 

#elif defined(__GNUC__) || defined(__clang__)
#define UNREACHABLE() __builtin_unreachable()
#define likely(x)       __builtin_expect((x),1)
#define unlikely(x)     __builtin_expect((x),0)
#elif defined(_MSC_VER)

#define UNREACHABLE() __assume(0)
#define ASSERT(x) __assume(x)

#else
//null pointer dereference to signal unreachability
#define UNREACHABLE() (*(int*)0 = 0)
#endif

#ifndef ASSERT
#include <stdbool.h>
static inline void ASSERT(bool x){
    if(!x){UNREACHABLE();}
}
// #define ASSERT(x) if(!x){UNREACHABLE();}
#endif

#ifndef likely
#define likely(x)
#define unlikely(x) 
#endif

static inline void* null_check(void* p){
	if(p==NULL){
		perror("went oom\n");
		exit(1);
	}
	return p;
}

#endif// UTILS_H