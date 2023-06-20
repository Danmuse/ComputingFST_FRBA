#ifndef _BINARY_CONVERTER_H_
#define _BINARY_CONVERTER_H_

#include "utils.h"

typedef enum {
	BIN =	0,
	OCT =	1,
	HEX =	2,
	DEC =	3
} BASE_t;

/// TODO: char* itoa(uint16_t, char*, uint8_t);

char* DecimalSplit_Binary(char*, char*);

char* DecimalMinus_Binary(char*, char*);

char* DecimalSplit_Octal(char*, char*);

char* DecimalSplit_Hexa(char*, char*);

char* DecimalSplit_SomeBase(char*, char*, BASE_t);

#endif // _BINARY_CONVERTER_H_