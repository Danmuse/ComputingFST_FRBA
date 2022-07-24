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
	int random = rand() % 25;
	int prompt = is_encrypt(src);
	if(prompt == 0) {
		while(*src != '\0') {
			if(*src > 64 && *src < 91) {
				if(*src + random > 90) dest[pos] = *src + random - 26;
				else dest[pos] = *src + random;
			}
			// else if((*src > 47 && *src < 58) || *src == 32) dest[pos] = *src;
			else if(*src == 32) dest[pos] = *src;
			pos++;
			src++;
		}
	} else random = -1;
	return random;
}

/**************************************************************************************************
 * Funcion que realiza el proceso inverso de la función anterior. Recibe un string y una cantidad *
 * y debe desplazar en sentido inverso las letras para recuperar el texto original                *
 **************************************************************************************************/

void decrypt_letters(char *src, char *dest, int random) {
	
}

/**************************************************************************
 * Para encriptar los números del string el procedimiento será reemplazar *
 * cada uno de sus dígitos por los caracteres que correspondan            *
 **************************************************************************/

void encrypt_numbers(char *src, char *dest) {
	size_t pos = 0;
	while(*src != '\0') {
		switch(*src) {
			case '0': dest[pos] = '$'; break;
			case '1': dest[pos] = '%'; break;
			case '2': dest[pos] = '&'; break;
			case '3': dest[pos] = '*'; break;
			case '4': dest[pos] = '@'; break;
			case '5': dest[pos] = '!'; break;
			case '6': dest[pos] = '+'; break;
			case '7': dest[pos] = '='; break;
			case '8': dest[pos] = '8'; break;
			case '9': dest[pos] = '9'; break;
			case ' ': dest[pos] = ' '; break;
			default: dest[pos] = *src; break;
		}
		// else if((*src > 64 && *src < 91) || *src == 32) dest[pos] = *src;
		// if(*src == 32) dest[pos] = *src;
		pos++;
		src++;
	}
}

/*************************************************************
 * Funcion analoga a la anterior para desencriptar el numero *
 *************************************************************/

void decrypt_numbers(char *src, char *dest) {
	
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
			buffer = 1;
			break;	
		}
		src++;
	}
	return buffer;
}
