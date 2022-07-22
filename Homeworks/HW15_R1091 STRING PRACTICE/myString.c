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
 
#include "myString.h"
#include <stdio.h>
#define SIZE 100

void init(char *str) { *str = '\0'; }

uint8_t repeatedChar(char *str, char caracter) {
	uint8_t amount = 0;
	while(*str != '\0') {
		if(*str == caracter) amount++;
		str++;
	}
	return amount;
}

void invest_string(char *str) {
	size_t i;
	uint8_t strlen = 0;
	char invest_str[SIZE];
	for(i = 0; str[i] != '\0'; i++) strlen++;
	for(i = 0; i < strlen; i++) invest_str[i] = str[(strlen - 2) - i];
	for(i = 0; invest_str[i] != '\0'; i++) str[i] = invest_str[i];
}

void upperCase(char *str) {
	while(*str != '\0') {
		if(*str >= 'a' && *str <= 'z') *str -= 32;
		str++;
	}
}

void lowerCase(char *str) {
	while(*str != '\0') {
		if(*str >= 'A' && *str <= 'Z') *str += 32;
		str++;
	}
}

void title(char *str) {
	size_t i;
	uint8_t st_spot = 0;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] == 32) st_spot = 1;
		if(i == 0 && (*str >= 'a' && *str <= 'z')) str[i] = str[i] - 32;
		else if(st_spot == 1 && (str[i] >= 'a' && str[i] <= 'z')) {
			str[i] -= 32;
			st_spot = 0;
		}
	}
}

void deleteSpots(char *str) {
	size_t i;
	uint8_t count_spot = 0;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] == 32) count_spot++;
		else str[i - count_spot] = str[i];
	}
	str[i - count_spot] = '\0'; // Se excluyen los caracteres basura inutilizados debido a alterar la posicion
}

uint8_t amountWords(char *str) {
	size_t i;
	uint8_t amount = 0, st_spot = 1;
	for(i = 0; str[i] != '\0'; i++) {
		if(str[i] == 32) st_spot = 1;
		else if (st_spot == 1 && str[i] > 32) { // Se excluyen los caracteres ASCCI de control
			amount++;
			st_spot = 0;
		}
	}
	return amount;
}

uint8_t alphanumeric(char *str) {
	uint8_t status = 0, st_alpha = 0, st_numeric = 0;
	while(*str != '\0') {
		if(*str > 32) {
			if(*str < 48 && *str > 57) st_alpha = 1;
			else st_numeric = 1;
		}
		str++;
	}
	if(st_alpha == 1 && st_numeric == 1) status = 0;
	else if(st_alpha == 1 && st_numeric == 0) status = 1;
	else if(st_alpha == 0 && st_numeric == 1) status = 2;
	printf("%u\t%u\t%u\n", status, st_alpha, st_numeric);
	return status;
}

uint8_t numeric(char *str) {
	uint8_t status = 0, st_alpha = 0, st_numeric = 0;
	while(*str != '\0') {
		if(*str > 32) {
			if(*str < 48 && *str > 57) st_alpha = 1;
			else st_numeric = 1;
		}
		str++;
	}
	if(st_alpha == 1 && st_numeric == 0) status = 1;
	else if(st_alpha == 0 && st_numeric == 1) status = 2;
	printf("%u\t%u\t%u\n", status, st_alpha, st_numeric);
	return status;
}
