/***********************************************************************************************************************
 * Realize una funcion que reciba un numero positivo en base 2 en formato de string y devuelva el equivalente decimal  *
 * Realize una funcion que reciba un numero positivo en base 8 en formato de string y devuelva el equivalente decimal  *
 * Realize una funcion que reciba un numero positivo en base 16 en formato de string y devuelva el equivalente decimal *
 * Para lo que refiere las funciones anteriores, devuelva "-1" en caso de error en la conversion                       *
 * Realize una funcion que imprima un numero en bases octal, decimal y hexadecimal                                     *
 ***********************************************************************************************************************/
 
// CORTEX 1769

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX_SIZE 16

typedef __UINT8_TYPE__ uint8_t;

uint8_t ChooseMenuOption(void);
char* Insert_String(char*, size_t);
char* strupper(char*);
int Binary_Decimal(char*);
int Octal_Decimal(char*);
int Hexa_Decimal(char*);

int main(void) {
	int result;
	char input_string[MAX_SIZE];
	while(1) {
		switch(ChooseMenuOption()) {
			case 0:
				return EXIT_SUCCESS;
			break;
			case 1:
				printf("Ingrese el valor binario que desea convertir: ");
				Insert_String(input_string, MAX_SIZE);
				result = Binary_Decimal(input_string);
				if (result < 0) printf("El valor ingresado no se corresponde a la base\n");
				else printf("El resultado en decimal es: %d\n", result);
			break;
			case 2: 
				printf("Ingrese el valor octal que desea convertir: ");
				Insert_String(input_string, MAX_SIZE);
				result = Octal_Decimal(input_string);
				if (result < 0) printf("El valor ingresado no se corresponde a la base\n");
				else printf("El resultado en decimal es: %d\n", result);
			break;
			case 3: 
				printf("Ingrese el valor haxadecimal que desea convertir: ");
				Insert_String(input_string, MAX_SIZE);
				result = Hexa_Decimal(input_string);
				if (result < 0) printf("El valor ingresado no se corresponde a la base\n");
				else printf("El resultado en decimal es: %d\n", result);
			break;
			default:
			break;
		}
	}
}

uint8_t ChooseMenuOption(void) {
	uint8_t option;
	bool checkValidEntry;
	printf("\nSeleccione alguna opcion...\n");
	printf("[0] - Finalizar\n");
	printf("[1] - Convertir de binario a decimal\n");
	printf("[2] - Convertir de octal a decimal\n");
	printf("[3] - Convertir de hexadecimal a decimal\n");
	while (!checkValidEntry) {
		printf("\nDefina su opcion: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			printf("Opcion invalida\n");
			while (getchar() != '\n');
		} else if (option > 3) {
			checkValidEntry = false;
			printf("Opcion invalida\n");
		}
	}
	return option;
}

char* Insert_String(char *buffer, size_t size) { 
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
	fgets(buffer, size, stdin);
	size = strlen(buffer);
	buffer[size - 1] = '\0';
	return buffer;
}

char* strupper(char* str) {
	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z') *str -= 32;
		str++;
	}
	return str;
} 

int Binary_Decimal(char* input_string) {
	size_t i, lenght = strlen(input_string);
	int accumulator = 0, position = 0;
	for (i = 0; i < lenght; i++) {
		if (input_string[lenght - i - 1] != '1' && input_string[lenght - i - 1] != '0') return -1;
		accumulator += (input_string[lenght - i - 1] - '0') * pow(2, position);
		position++;
	}
	return accumulator;
}

int Octal_Decimal(char* input_string) {
	size_t i, lenght = strlen(input_string);
	int accumulator = 0, position = 0;
	for (i = 0; i < lenght; i++) {
		if (input_string[lenght - i - 1] >= '0' && input_string[lenght - i - 1] <= '7') {
			accumulator += (input_string[lenght - i - 1] - '0') * pow(8, position);
			position++;
		} else return -1;
	}
	return accumulator;
}

int Hexa_Decimal(char* input_string) {
	size_t i, lenght = strlen(input_string);
	int accumulator = 0, position = 0;
	strupper(input_string);
	for (i = 0; i < lenght; i++) {
		if (input_string[lenght - i - 1] >= '0' && input_string[lenght - i - 1] <= '9') {
			accumulator += (input_string[lenght - i - 1] - '0') * pow(16, position);
			position++;
		} else if (input_string[lenght - i - 1] >= 'A' && input_string[lenght - i - 1] <= 'F') {
			accumulator += (input_string[lenght - i - 1] - 'A' + 10) * pow(16, position);
			position++;
		} else return -1;
	}
	return accumulator;
}
