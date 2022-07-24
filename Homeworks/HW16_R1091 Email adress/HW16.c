/*****************************************************************************************
 * Solicitar por ingreso de teclado el nombre, apellido y generar una direccion de email *
 * cumpliendo la siguiente regla: Primer letra del nombre, 8 primeras letra del apellido *
 * y finalizando con "@frba.utn.edu.ar"                                                  *
 *****************************************************************************************/

#include <stdio.h>
#define SIZE 26

char *email(char *, char **, int);
void str_lowerCase(char *);
char *my_strcat(char *, char *);

int main(int argc, char *argv[]) {
	char str[SIZE];
	if(argc > 1) {
		email(str, argv, argc);
		printf("Su email es: ");
		puts(str);
	} else printf("Debe ingresar en la ejecucion del programa su primer nombre y el apellido\n");
	// for(int i = 32; i < 200; i++) printf("%d - %c\n", i, i); // Monitoriza el caracter ASCCI correspondiente
	return 0;
}

char *email(char *src, char *argv[], int argc) {
	size_t i, j;
	char domain[17] = "@frba.edu.utn.ar";
	int cant = argc - 1, count = 0, surnameLetters = 0;
	for(i = 0; i < cant; i++) {
		if(i == 0) {
			src[count] = *argv[i + 1];
			count++;
		} else {
			for(j = 0; *(argv[i + 1] + j) != '\0'; j++) {
				char *ptr = argv[i + 1] + j;
				if((*ptr > 64 && *ptr < 91 && surnameLetters < 8) || (*ptr > 96 && *ptr < 123 && surnameLetters < 8)) {
					src[count] = *ptr;
					surnameLetters++;
					count++;
				}
			}
		}
	}
	src[count] = '\0';
	str_lowerCase(src);
	my_strcat(domain, src);
	return src;
}

void str_lowerCase(char *src) {
	while(*src != '\0') {
		if(*src > 64 && *src < 91) *src += 32;
		src++;
	}
}

char *my_strcat(char *src, char *dest) {
	size_t i;
	int pos = 0; 
	for(i = 0; dest[i] != '\0'; i++) pos++; // my_strlen
	for(i = 0; src[i] != '\0'; i++) dest[pos + i] = src[i];
	dest[pos + i] = '\0';
	return dest;
}
