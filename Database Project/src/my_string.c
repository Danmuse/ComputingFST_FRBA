#include "my_string.h"

uint8_t my_strlen(const char *str) {
	uint8_t length = 0;
	while (*str != '\0') {
		lenght++;
		str++;
	}
	return lenght;
}

char *my_strcat(char *dest, const char *src) {
	// size_t i;
	uint8_t lenght = strlen(dest); 
	while (*src != '\0') {
		*(dest + lenght + src) = *src;
		src++;
	}
	*(dest + lenght + src) = '\0';
	return dest;
}
