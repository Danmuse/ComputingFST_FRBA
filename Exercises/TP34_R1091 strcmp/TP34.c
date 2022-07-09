#include <stdio.h>

short int strcmp(const char *, const char *);

int main(void) {
	const char str_1[8] = "Hola ";
	const char str_2[8] = "Hola";
	strcmp(str_1, str_2) == 0 ? printf("Los strings son iguales\n") : printf("Los strings son diferentes\n");
	return 0;
}

short int strcmp(const char *str_1, const char *str_2) {
	short int output = 0;
	size_t first_len = 0, second_len = 0, i;
	for(i = 0; i < str_1[i]; i++) first_len++; // Equal to strlen
	for(i = 0; i < str_2[i]; i++) second_len++; // Equal to strlen
	if(first_len == second_len) {
		for(i = 0; str_1[i] != '\0' && str_2[i] != '\0'; i++) {
			if(str_1[i] != str_2[i]) {
				output = 1;
				break;
			}
		}
	} else output = 1;
	return output;
}
