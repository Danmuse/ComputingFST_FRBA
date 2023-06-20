#include "functions.h"
#define SIZE 13

int main(int argc, char *argv[]) {
	size_t i;
	int input_function = 0;
	char str[SIZE], genre, DNI[SIZE], CUIT[SIZE];
	if (argc > 1) { // Esta condicion se ejecutara siempre que exista algun texto ingresado a continuacion del ejecutable
		my_strcat(str, argv, argc);
		printf("Texto ingresado: ");
		puts(str);
		genre = *str;
		for (i = 0; *(argv[2] + i) != '\0'; i++) *(DNI + i) = *(argv[2] + i);
		*(DNI + i) = '\0';
		input_function = cuit(genre, DNI, CUIT);
		switch (input_function) {
			case 0:
				printf("== CUIT ==\n%s\n", CUIT);
			break;
			case 1:
				printf("== ERROR ==\nEl tipo de persona juridica no es valido...\n");
				printf("Posibles valores M o F\n");
			break;
			case 2:
				printf("== ERROR ==\nEl tipo de persona juridica no es valido...\n");
				printf("El DNI debe tener 10 caracteres numericos\n");
			break;
			case 3:
				printf("== ERROR ==\nEl tipo de persona juridica no es valido...\n");
				printf("Posibles valores M o F\n");
				printf("El DNI debe tener 8 caracteres numericos\n");
			break;
			default:
			break;
		}
	} else printf("En la ejecucion del programa debe ingresar su genero (M o F) y su DNI\n");
	return 0;
}
