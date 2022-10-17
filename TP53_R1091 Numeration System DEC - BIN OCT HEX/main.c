/*********************************************************************************************************************************
* Realizar una funcion que reciba una cantidad y un array de char vacío donde deberá colocar un string con el numero convertido  *
* en binario utilizando el metodo de las divisiones.                                                                             *
* Repita el ejericio anterior, pero utilizando el metodo de las restas.                                                          *
* Modifique la funcion anterior para que reciba un tercer parametro, que indique la base de destino a la cual se desea convertir *
* el numero devuelto por la funcion.                                                                                             *
*********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#define MAX_SIZE 30

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;

typedef enum {
	BIN =	0,
	OCT =	1,
	HEX =	2,
	DEC =	3
} BASE_t;

uint8_t ChooseMenuOption_1(void);
uint8_t ChooseMenuOption_2(void);
uint8_t CheckValidString(char*);
// char* itoa(uint16_t, char*);
char* strreverse(char*);
char* Insert_String(char*, size_t);
char* DecimalSplit_Binary(char*, char*);
char* DecimalMinus_Binary(char*, char*);
char* DecimalSplit_Octal(char*, char*);
char* DecimalSplit_Hexa(char*, char*);
char* DecimalSplit_SomeBase(char*, char*, BASE_t);

int main(void) {
	char decimal_string[MAX_SIZE], result_string[MAX_SIZE];
	while(1) {
		switch(ChooseMenuOption_1()) {
			case 0:
				return EXIT_SUCCESS;
			break;
			case 1:
				printf("Ingrese el valor decimal que desea convertir: ");
				Insert_String(decimal_string, MAX_SIZE);
				!CheckValidString(decimal_string) ? 
				printf("El resultado en binario es: %s\n", DecimalSplit_Binary(result_string, decimal_string)) :
				printf("El valor ingresado no se corresponde a la base\n");
			break;
			case 2:
				printf("Ingrese el valor decimal que desea convertir: ");
				Insert_String(decimal_string, MAX_SIZE);
				!CheckValidString(decimal_string) ? 
				printf("El resultado en binario es: %s\n", DecimalMinus_Binary(result_string, decimal_string)) :
				printf("El valor ingresado no se corresponde a la base\n");
			break;
			case 3:
				printf("Ingrese el valor decimal que desea convertir: ");
				Insert_String(decimal_string, MAX_SIZE);
				if (!CheckValidString(decimal_string)) {
					BASE_t base = (BASE_t)ChooseMenuOption_2();
					DecimalSplit_SomeBase(result_string, decimal_string, base);
					if (base == BIN) printf("El resultado en binario es: %s\n", result_string);
					else if (base == OCT) printf("El resultado en octal es: %s\n", result_string);
					else if (base == HEX) printf("El resultado en haxadecimal es: %s\n", result_string);
				} else printf("El valor ingresado no se corresponde a la base\n");
			break;
			default:
			break;
		}
	}
}

uint8_t ChooseMenuOption_1(void) {
	uint8_t option;
	bool checkValidEntry;
	printf("\nSeleccione alguna opcion...\n");
	printf("[0] - Finalizar\n");
	printf("[1] - Convertir de decimal a binario (Metodo de division)\n");
	printf("[2] - Convertir de decimal a binario (Metodo de resta)\n");
	printf("[3] - Convertir de decimal a una base [BINARIO - OCTAL - HEXADECIMAL]\n");
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

uint8_t ChooseMenuOption_2(void) {
	uint8_t option;
	bool checkValidEntry;
	printf("\nSeleccione alguna opcion...\n");
	printf("[0] - Convertir de decimal a BINARIO\n");
	printf("[1] - Convertir de decimal a OCTAL\n");
	printf("[2] - Convertir de decimal a HEXADECIMAL\n");
	while (!checkValidEntry) {
		printf("\nDefina su opcion: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			printf("Opcion invalida\n");
			while (getchar() != '\n');
		} else if (option > 2) {
			checkValidEntry = false;
			printf("Opcion invalida\n");
		}
	}
	return option;
}

uint8_t CheckValidString(char* str) {
	while (*str != '\0') {
		if (!(*str >= '0' && *str <= '9')) return -1;
		str++;
	}
	return EXIT_SUCCESS;
}

/*
char* itoa(uint16_t value, char* str) {
	sprintf(str, "%hu", value);
	return str;
}
*/

char* strreverse(char* str) {
	size_t lenght = strlen(str);
	uint8_t left, right;
	char aux;
	for (left = 0, right = lenght - 1; left < (lenght / 2); left++, right--) {
		aux = str[left];
		str[left] = str[right];
		str[right] = aux;
	}
	return str;
}

char* Insert_String(char *buffer, size_t size) { 
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
	fgets(buffer, size, stdin);
	size = strlen(buffer);
	buffer[size - 1] = '\0';
	return buffer;
}

char* DecimalSplit_Binary(char* output_string, char* input_string) {
	size_t i;
	uint16_t decimal = atoi(input_string);
	for (i = 0; decimal >= 1; i++) {
		output_string[i] = (decimal % 2) + '0';
		decimal /= 2;
	}
	output_string[i] = '\0';
	return strreverse(output_string);
}

char* DecimalMinus_Binary(char* output_string, char* input_string) {
	size_t i;
	uint16_t decimal = atoi(input_string);
	strcpy(output_string, "\0");
	printf("Current string: %s\n", output_string);
	for (i = 0; decimal > 0; i++) {
		if (decimal < pow(2, i) && decimal > pow(2, i - 1)) {
			output_string[i] = '1';
			// output_string[i + 1] = '\0';
			printf("Current decimal: %hu - %ld\n", decimal, i);
			printf("Current string: %s\n", output_string);
			decimal -= pow(2, i - 1);
			i = 0;
		} else output_string[i] = '0';
	}
	// output_string[strlen(output_string) + 1] = '\0';
	return output_string;
}

char* DecimalSplit_Octal(char* output_string, char* input_string) {
	
	return strreverse(output_string);
}

char* DecimalSplit_Hexa(char* output_string, char* input_string) {
	
	return strreverse(output_string);
}

char* DecimalSplit_SomeBase(char* output_string, char* input_string, BASE_t base) {
	switch(base) {
		case BIN:
			return DecimalSplit_Binary(output_string, input_string);
		break;
		case OCT:
			return DecimalSplit_Octal(output_string, input_string);
		break;
		case HEX:
			return DecimalSplit_Hexa(output_string, input_string);
		break;
		default:
		break;
	}
}
