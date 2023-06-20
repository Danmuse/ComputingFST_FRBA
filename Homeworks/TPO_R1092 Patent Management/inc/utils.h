#ifndef _UTILS_H_
#define _UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

typedef enum {
	FAILURE = -1,
    SUCCESS = EXIT_SUCCESS,
	ERROR   = EXIT_FAILURE
} status_t;

void checkAllocate(void *pointer);

#endif // _UTILS_H_