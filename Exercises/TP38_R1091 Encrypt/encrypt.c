#include "encrypt.h"

/***************************************************************************
 * Funcion para concatenar los argumentos dados en formato de cadena unica *
 ***************************************************************************/

char *my_strcat(char *src, char *argv[], int argc) {
	size_t i, j;
	uint8_t cant = argc - 1, count = 0;
	for(i = 0; i < cant; i++) {
		// printf("#%ld - %s - %c\n", i, argv[i + 1], *(argv[i + 1] + 1));
		for(j = 0; *(argv[i + 1] + j) != '\0'; j++) {	// IDEM: while(*argv[i + 1] != '\0') {
			src[count] = *(argv[i + 1] + j);	// IDEM: printf("%c\n", *(argv[i + 1]));
			count++;				// IDEM: argv[i + 1]++;
		}
		if(i < cant - 1) {
			src[count] = ' ';
			count++;
		} 
	}
	src[count] = '\0';
	return src;
}

/**********************************************************************************************
 * Funcion que debe generar un desplazamiento alfabetico de cada una de las letras del string *
 * recibido como argumento, una cantidad aleatoria de posiciones (entre 1 y 25). En caso de   *
 * sobrepasar la ‘Z’, se debera continuar con la ‘A’. Los numeros y espacios deben permanecer *
 * invariables. La funcion debe retornar la cantidad de posiciones que se han desplazado los  *
 * caracteres.                                                                                *
 **********************************************************************************************/

int scroll_letters(char *src, char *dest) {
	size_t pos = 0;
	char str_swap[SIZE]; // Cadena de intercambio para encriptar los numeros
	int random = rand() % 25; // Almacena el valor del numero random
	int prompt = is_encrypt(src); // Verifica que el texto ingresado sea encriptable
	if(prompt == 0) {
		while(*src != '\0') {
			if(*src > 64 && *src < 91) {
				if(*src + random > 90) dest[pos] = *src + random - 26;
				else dest[pos] = *src + random;
			} else if(*src > 47 && *src < 58) {
				encrypt_numbers(src, str_swap);
				dest[pos] = *str_swap;
			} else if(*src == 32) dest[pos] = *src;
			pos++;
			src++;
		}
		dest[pos] = '\0';
	} else random = prompt;
	return random;
}

/**************************************************************************************************
 * Funcion que realiza el proceso inverso de la función anterior. Recibe un string y una cantidad *
 * y debe desplazar en sentido inverso las letras para recuperar el texto original                *
 **************************************************************************************************/

void decrypt_letters(char *src, char *dest, int random) {
	size_t pos = 0;
	char str_swap[SIZE]; // Cadena de intercambio para encriptar los numeros
	while(*src != '\0') {
		if(*src > 64 && *src < 91) {
			if(*src - random < 65) dest[pos] = *src - random + 26;
			else dest[pos] = *src - random;
		} else if(*src == 36 || *src == 37 || *src == 38 || *src == 42 || *src == 64 || *src == 33 || *src == 43 || *src == 61 || *src == '8' || *src == '9') { 
			// Revisar los caracteres ASCCI
			decrypt_numbers(src, str_swap);
			dest[pos] = *str_swap;
		} else if(*src == 32) dest[pos] = *src;
		pos++;
		src++;
	}
	dest[pos] = '\0';
}

/**************************************************************************
 * Para encriptar los números del string el procedimiento será reemplazar *
 * cada uno de sus dígitos por los caracteres que correspondan            *
 **************************************************************************/

void encrypt_numbers(char *src, char *dest) {
	size_t pos = 0;
	while(*src != '\0') {
		switch(*src) {
			case '0': dest[pos] = '$'; break; // ASCCI: 36
			case '1': dest[pos] = '%'; break; // ASCCI: 37
			case '2': dest[pos] = '&'; break; // ASCCI: 38
			case '3': dest[pos] = '*'; break; // ASCCI: 42
			case '4': dest[pos] = '@'; break; // ASCCI: 64
			case '5': dest[pos] = '!'; break; // ASCCI: 33
			case '6': dest[pos] = '+'; break; // ASCCI: 43
			case '7': dest[pos] = '='; break; // ASCCI: 61
			default: dest[pos] = *src; break;
		}
		pos++;
		src++;
	}
}

/*************************************************************
 * Funcion analoga a la anterior para desencriptar el numero *
 *************************************************************/

void decrypt_numbers(char *src, char *dest) {
	size_t pos = 0;
	while(*src != '\0') {
		switch(*src) {
			case '$': dest[pos] = '0'; break;
			case '%': dest[pos] = '1'; break;
			case '&': dest[pos] = '2'; break;
			case '*': dest[pos] = '3'; break;
			case '@': dest[pos] = '4'; break;
			case '!': dest[pos] = '5'; break;
			case '+': dest[pos] = '6'; break;
			case '=': dest[pos] = '7'; break;
			default: dest[pos] = *src; break;
		}
		pos++;
		src++;
	}
}

/************************************************************************************************
 * Funcion que devuelve 0 en caso de OK o -1 para falso, definiendo que no es posible encriptar *
 * un string que tenga caracteres no alfanumericos, con excepción del espacio ‘ ‘               * 
 ************************************************************************************************/

int is_encrypt(char *src) {
	int buffer = 0;
	while(*src != '\0') {
		if((*src > 64 && *src < 91) || (*src > 96 && *src < 123) || (*src > 47 && *src < 58) || *src == 32) {
			if(*src > 96 && *src < 123) *src = *src - 32; // *src = *src - ('a' - 'A');
		} else {
			buffer = -1;
			break;	
		}
		src++;
	}
	return buffer;
}
