#include <stdio.h>

char *strncat(char *, char *, size_t n);

int main(void) {
	char str_1[6] = "Hola ";
	char str_2[6] = "Mundo";
	printf("El string resultante es \"%s\"\n", strncat(str_1, str_2, 2)); // Output "Hola Mu"
	return 0;
}

char *strncat(char *dest, char *src, size_t n) {
	size_t dest_len = 0, i;	
	for(i = 0; i < dest[i]; i++) dest_len++; // Equal to strlen
	for(i = 0; i < n && src[i] != '\0'; i++) dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';
	return dest;
}
