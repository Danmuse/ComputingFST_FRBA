#include <stdio.h>
#define SIZE 11

char *strcpy(char *, const char *);

int main(void) {
	char *str = "Hello World"; // Constant String literal - ONLY READ
	char copy[SIZE] = "'\\0'";
	printf("%s\t%s\n", str, copy);
	strcpy(copy, str);
	printf("%s\t%s\n", str, copy);
	return 0;
}

char *strcpy(char *dest, const char *src) {
	size_t i; // Equal to unsigned long
	for (i = 0; src[i] != '\0'; i++) dest[i] = src[i];
	dest[i] = '\0';
	return dest;
}
