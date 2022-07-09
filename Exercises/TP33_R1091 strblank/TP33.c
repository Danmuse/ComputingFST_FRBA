#include <stdio.h>

void strblank(char *);

int main(void) {
	char str[11] = "Hola Mundo";
	printf("Before function: \"%s\"\n", str);
	strblank(str);
	printf("After function: \"%s\"\n", str);
	return 0;
}

void strblank(char *str) {
	size_t i;
	for(i = 0; str[i] != '\0'; i++) str[i] = 0;
}
