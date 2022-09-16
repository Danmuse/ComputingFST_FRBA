#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"
#define SIZE 50

typedef __UINT8_TYPE__ uint8_t;
typedef struct {
	char name[SIZE];
	char surname[SIZE];
} user_t

int main(void) {
	uint8_t output = 0
	char result_str;
	user_t user = {"Daniel", "Di Modica"};
	output = my_strlen(user.name);
	// my_strcpy(result_str, user.name);
	my_strcat(result_str, user.name);
	printf("El nombre posee %d caracteres", output);
	puts(result_str);
	return 0;
}
