/**********************************************************************************
 * Inicializar una cadena con '\0'                                                *
 * Contar la ocurrencia de un caracter en una cadena                              *
 * Invertir la cadena                                                             *
 * Convertir una cadena a mayusculas                                              *
 * Convertir una cadena a minusculas                                              *
 * Convertir una cadena a Titulo                                                  *
 * Remover todos los espacios                                                     *
 * Contar la cantidad de palabras                                                 *
 * Verificar si una cadena tiene todos sus caracteres alfanumericos (a-z A-Z 0-9) *
 * Verificar si en la cadena todos los caracteres son numeros (0-9)               *
 **********************************************************************************/

#include <stdio.h>
#include "myString.h"
#define SIZE 100

int main(void) {
	uint8_t option = 0, output_scanf = 0, out_function;
	char str[SIZE], caracter;
	printf("\nIngrese un string: ");
	fgets(str, sizeof(str), stdin);
	printf("Ingrese un caracter: ");
	output_scanf = scanf("%c", &caracter); // NOTA: Prohibido utilizar "scanf(...)" dentro de condicionales del tipo "switch(...)"
	printf("\nSeleccione alguna opcion...\n");
	printf("[0] - Inicializar el string con '\\0'\n");
	printf("[1] - Contar la aparicion del caracter ingresado\n");
	printf("[2] - Invertir String\n");
	printf("[3] - Convertir a mayusculas\n");
	printf("[4] - Convertir a minusculas\n");
	printf("[5] - Convertir a titulo\n");
	printf("[6] - Remover espacios\n");
	printf("[7] - Contar la cantidad de palabras\n");
	printf("[8] - Verificar la existencia absoluta de caracteres alfanumericos\n");
	printf("[9] - Verificar la existencia absoluta de caracteres numericos\n");
	
	while(1) {
		printf("\nDefina su opcion: ");
		output_scanf = scanf("%hhu", &option);
		if(option >= 0 && option <= 10) {
			switch(option) {
				case 0:
					init(str);
					printf("Resultado: ");
					puts(str);
					return EXIT_SUCCESS;
				break;
				case 1:
					out_function = repeatedChar(str, caracter);
					if(out_function != 0) printf("Se han encontrado %hhu coincidencias de '%c'\n", out_function, caracter);
					else printf("Caracter no encontrado...\n");
					return EXIT_SUCCESS;
				break;
				case 2:
					invest_string(str);
					printf("Resultado: ");
					puts(str);
					return EXIT_SUCCESS;
				break;
				case 3:
					upperCase(str);
					printf("Resultado: ");
					puts(str);
					return EXIT_SUCCESS;
				break;
				case 4:
					lowerCase(str);
					printf("Resultado: ");
					puts(str);
					return EXIT_SUCCESS;
				break;
				case 5:
					title(str);
					printf("Resultado: ");
					puts(str);
					return EXIT_SUCCESS;
				break;
				case 6:
					deleteSpots(str);
					printf("Resultado: ");
					puts(str);
					return EXIT_SUCCESS;
				break;
				case 7:
					out_function = amountWords(str);
					printf("Se han encontrado %hhu palabras\n", out_function);
					return EXIT_SUCCESS;
				break;
				case 8:
					out_function = alphanumeric(str);
					if(out_function == 0) printf("Todos los elementos de la cadena son alfanumericos\n");
					else if(out_function == 1) printf("La cadena solo esta compuesta por letras\n");
					else printf("La cadena solo esta compuesta por numeros\n");
					return EXIT_SUCCESS;
				break;
				case 9:
					out_function = numeric(str);
					if(out_function == 0) printf("Todos los elementos de la cadena son numericos\n");
					else if(out_function == 1) printf("No todos los elementos de la cadena son numericos\n");
					else printf("La cadena no posee numeros\n");
					return EXIT_SUCCESS;
				break;
				default:
				break;
			}
		} else if(output_scanf != 1) {
			printf("Opcion invalida\n");
			return EXIT_FAILURE; // Debug
		} else printf("Opcion invalida\n");
	}
}
