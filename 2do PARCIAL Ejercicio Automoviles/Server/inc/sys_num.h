#ifndef SYS_NUM_H_
#define SYS_NUM_H_

#include "utils.h"

char* Insert_String(char*, size_t);

//**************************************//
// Section Converter: BIN OCT HEX - DEC //
//**************************************//

char* strupper(char*);
int Binary_Decimal(char*);
int Octal_Decimal(char*);
int Hexa_Decimal(char*);

//**************************************//
// Section Converter: DEC - BIN OCT HEX //
//**************************************//

typedef enum {
	BIN =	0,
	OCT =	1,
	HEX =	2,
	DEC =	3
} BASE_t;

uint8_t CheckValidString(char*);
char* strreverse(char*);
char* DecimalSplit_Binary(char*, char*);
char* DecimalMinus_Binary(char*, char*);
char* DecimalSplit_Octal(char*, char*);
char* DecimalSplit_Hexa(char*, char*);
char* DecimalSplit_SomeBase(char*, char*, BASE_t);

#endif // SYS_NUM_H_
