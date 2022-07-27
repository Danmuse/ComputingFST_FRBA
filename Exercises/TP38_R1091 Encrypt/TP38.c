/**********************************
 * Pacial de 2020 - Informatica 1 *
 **********************************/

#include <stdio.h>
#include "encrypt.h"

// argc --> numero de palabras (incluido el nombre del programa)
// argv --> vector de punteros a cadena, donde cada elemento apunta a una palabra (ONLY READ)

int main(int argc, char *argv[]) {
	int out_function;
	char str[SIZE], dest[SIZE], invest_dest[SIZE];
	srand(getpid());
	
	if(argc > 1) {
		// "%hhu" es la representacion de "unsigned short int" o "uint8_t"
		my_strcat(str, argv, argc);
		out_function = scroll_letters(str, dest);
		if(out_function != -1) {
			printf("El texto encriptado es: ");
			puts(dest);
			decrypt_letters(dest, invest_dest, out_function);
			printf("El texto desencriptado es: ");
			puts(invest_dest);
		} else printf("No es posible encriptar el texto ingresado...\n");
	} else printf("Debe ingresar un argumento en la ejecucion del programa\n");
	return EXIT_SUCCESS;
}
