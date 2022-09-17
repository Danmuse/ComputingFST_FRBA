#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;

typedef struct {
	char name[SIZE];
	char surname[SIZE];
	uint16_t docket;
	uint8_t age;
} student_t;

typedef enum {
	FALSE = 0,
	TRUE = 1
} my_boolean;

my_boolean enter_struct(student_t *);
my_boolean check_exit(student_t *);
void show_struct(student_t *);
