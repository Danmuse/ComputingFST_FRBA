#include "functions.h"

char *my_strcat(char *src, char *argv[], int argc) { // Funcion para concatenar el texto ingresado a continuacion del ejecutable
	size_t i, j;
	int cant = argc - 1, count = 0;
	for(i = 0; i < cant; i++) {
		for(j = 0; *(argv[i + 1] + j) != '\0'; j++) {
			src[count] = *(argv[i + 1] + j);
			count++;				
		}
		
		// Agrega un espacio al string habiendo copiado la palabra anterior
		if(i < cant - 1) {
			src[count] = ' ';
			count++;
		}
	}
	src[count] = '\0';
	return src;
}

int cuit(char genre, char *DNI, char *CUIT) {
	size_t i;
	float average = 0;
	int output_function = 0, accumulator = 0, last_number = 0;
	output_function = validar_tipo(genre);
	if (output_function == 0 && validar_dni(DNI) == 2) output_function = 2;
	else if (output_function == 1 && validar_dni(DNI) == 2) output_function = 3;
	if (output_function == 0) { // En caso de no haber recibido ningun error de las funciones anteriores entonces...
		if (genre == 'M' || genre == 'm') {
			*CUIT = '2';
			accumulator += ('2' - '0') * 5;
			*(CUIT + 1) = '0';
			accumulator += ('0' - '0') * 4;
			*(CUIT + 2) = '-';
		} else if (genre == 'F' || genre == 'f') {
			*CUIT = '2';
			accumulator += ('2' - '0') * 5;
			*(CUIT + 1) = '7';
			accumulator += ('7' - '0') * 4;
			*(CUIT + 2) = '-';
		}
		for (i = 0; *(DNI + i) != '\0'; i++) {
			CUIT[i + 3] = *(DNI + i);
			if (i == 0 || i == 6) accumulator += (*(DNI + i) - '0') * 3;
			else if (i == 1 || i == 7) accumulator += (*(DNI + i) - '0') * 2;
			else if (i == 2) accumulator += (*(DNI + i) - '0') * 7;
			else if (i == 3) accumulator += (*(DNI + i) - '0') * 6;
			else if (i == 4) accumulator += (*(DNI + i) - '0') * 5;
			else if (i == 5) accumulator += (*(DNI + i) - '0') * 4;
		}
		average = (float) accumulator / 11;
		last_number = 11 - ((int) (average * 10)) % 10;
		if (last_number > 9) last_number = 9;
		*(CUIT + i + 3) = '-';
		*(CUIT + i + 4) = last_number + '0';
		*(CUIT + i + 5) = '\0';
	}
	return output_function;
}

int validar_tipo(char genre) {
	int output_function = 0;
	if (genre == 'M' || genre == 'm'|| genre == 'F' || genre == 'f') output_function = 0;
	else output_function = 1;
	return output_function;
}

int validar_dni(char *DNI) {
	int output_function = 0, count = 0;
	while (*DNI != '\0') {
		if (*DNI >= '0' && *DNI <= '9') output_function = 0;
		else output_function = 2;
		count++;
		DNI++;
	}
	if (count > 8) output_function = 2;
	return output_function;
}
