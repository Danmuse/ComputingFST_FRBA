#include "encrypt.h"

int scroll_letters(char *src, char *dest) {
	size_t pos = 0;
	int random = rand() % 25;
	int prompt = is_encrypt(src);
	if(prompt == 0) {
		while(*src != '\0') {
			if(*src > 64 && *src < 91) {
				if(*src + random > 90) dest[pos] = *src + random - 26;
				else dest[pos] = *src + random;
			}
			// else if((*src > 47 && *src < 58) || *src == 32) dest[pos] = *src;
			else if(*src == 32) dest[pos] = *src;
			pos++;
			src++;
		}
	} else random = -1;
	return random;
}

void decrypt_letters(char *src, char *dest, int random) {
	
}

void encrypt_numbers(char *src, char *dest) {
	size_t pos = 0;
	while(*src != '\0') {
		switch(*src) {
			case '0': dest[pos] = '$'; break;
			case '1': dest[pos] = '%'; break;
			case '2': dest[pos] = '&'; break;
			case '3': dest[pos] = '*'; break;
			case '4': dest[pos] = '@'; break;
			case '5': dest[pos] = '!'; break;
			case '6': dest[pos] = '+'; break;
			case '7': dest[pos] = '='; break;
			case '8': dest[pos] = '8'; break;
			case '9': dest[pos] = '9'; break;
			case ' ': dest[pos] = ' '; break;
			default:
				dest[pos] = *src;
				break;
		}
		// else if((*src > 64 && *src < 91) || *src == 32) dest[pos] = *src;
		// if(*src == 32) dest[pos] = *src;
		pos++;
		src++;
	}
}

void decrypt_numbers(char *src, char *dest) {
	
}

int is_encrypt(char *src) {
	int buffer = 0;
	while(*src != '\0') {
		if((*src > 64 && *src < 91) || (*src > 96 && *src < 123) || (*src > 47 && *src < 58) || *src == 32) {
			if(*src > 96 && *src < 123) *src = *src - 32; // *src = *src - ('a' - 'A');
		} else {
			buffer = 1;
			break;	
		}
		src++;
	}
	return buffer;
}
