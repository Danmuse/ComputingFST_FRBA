#include <stdio.h>

char *strcat(char *, char *);

int main(void) {
	char str_1[6] = "Hola ";
	char str_2[6] = "Mundo";
	printf("El string resultante es \"%s\"\n", strcat(str_1, str_2));
	return 0;
}

char *strcat(char *dest, char *src) {
	size_t dest_len = 0, i;	
	for(i = 0; i < dest[i]; i++) dest_len++; // Equal to strlen
	for(i = 0; src[i] != '\0'; i++) dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return dest;
}
