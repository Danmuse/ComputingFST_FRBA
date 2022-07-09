/***********************************************************
 * Realice una funcion que recibe un puntero a un string   *
 * y devuelve la longitud de la cadena sin incluir el '\0' *
 * En otras palabras, rediseñar la funcion 'strlen'        *
 ***********************************************************/

#include <stdio.h>

long int strlen(char *);

int main(void) {
	char str[50] = "Esta es una funcion comprendida por strings";
	printf("Tamaño del array es %ld", strlen(str)); // No incluye el '\0'
	return 0;
}

long int strlen(char *text) {
	long int buffer = 0;
	char letter = *text;
	while(letter != 0) {
		buffer++;
		letter = *(text + buffer);
	}
	return buffer;
}
