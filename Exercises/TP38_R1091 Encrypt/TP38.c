/**********************************
 * Pacial de 2020 - Informatica 1 *
 **********************************/

#include "encrypt.h"
#define SIZE 30

// argc --> numero de palabras (incluido el nombre del programa)
// argv --> vector de punteros a cadena, donde cada elemento apunta a una palabra (ONLY READ)

int main(int argc, char *argv[]) {
	int out_function;
	uint8_t option = 0;
	char str[SIZE], dest[SIZE];
	srand(getpid());
	
	if(argc > 1) {
		printf("\nSeleccione alguna opcion...\n");
		printf("[0] - Encriptar letras\n");
		printf("[1] - Desencriptar letras\n");
		printf("[2] - Encriptar numeros\n");
		printf("[3] - Desencriptar numeros\n");
		printf("[4] - ¿Es posible encriptarlo?\n");
		
		printf("\nDefina su opcion: ");
		scanf("%hhu", &option); // "%hhu" es la representacion de "unsigned short int" o "uint8_t"
		if(option >= 0 && option <= 4) {
			my_strcat(str, argv, argc);
			switch(option) {
				case 0:
					out_function = scroll_letters(str, dest);
					printf("Resultado: ");
					out_function != -1 ? printf("%s\t\t%s\n", str, dest) : printf("No es posible encriptarlo\n");
					// puts(str);
				break;
				case 1:
					decrypt_letters(str, dest, out_function);
					printf("Resultado: ");
					puts(str);
				break;
				case 2:
					encrypt_numbers(str, dest);
					printf("Resultado: ");
					puts(str);
				break;
				case 3:
					decrypt_numbers(str, dest);
					printf("Resultado: ");
					puts(str);
				break;
				case 4:
					is_encrypt(str);
					printf("Resultado: ");
					puts(str);
				break;
				default:
				break;
			}
		} else printf("Opcion invalida\n");
	} else printf("\nDebe ingresar un argumento en la ejecucion del programa\n");
	return EXIT_SUCCESS;
}
