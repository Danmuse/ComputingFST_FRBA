#include "utils.h"

void checkAllocate(void *pointer) {
    if (!pointer) {
        fprintf(stderr, "Critical error has occurred!");
        exit(EXIT_FAILURE);
    }
}

char* strreverse(char* str) {
	size_t lenght = strlen(str);
	uint8_t left, right;
	char aux;
	for (left = 0, right = lenght - 1; left < (lenght / 2); left++, right--) {
		aux = str[left];
		str[left] = str[right];
		str[right] = aux;
	}
	return str;
}