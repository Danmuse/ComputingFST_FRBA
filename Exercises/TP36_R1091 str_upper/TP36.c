/*************************************************************
 * Realice una funcion que recibe un puntero a un string     *
 * El prototipo debe ser 'str_upper_case(char *);'           *
 * En otras palabras, rediseñar la funcion 'toUpper(char *)' *
 *************************************************************/

#include <stdio.h>

void str_upper_case(char *);

int main(void) {
	char str[50] = "Esta es una funcion comprendida por strings";
	str_upper_case(str);
	puts(str);
	return 0;
}

void str_upper_case(char *text) {
	while(*text != 0) {
		if(*text > 96 && *text < 123) *text = *text - 32;
		text++;
	}
}
