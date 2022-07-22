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
 
#include <stdlib.h>

typedef __UINT8_TYPE__ uint8_t;

void init(char *);
uint8_t repeatedChar(char *, char);
void invest_string(char *);
void upperCase(char *);
void lowerCase(char *);
void title(char *);
void deleteSpots(char *);
uint8_t amountWords(char *);
uint8_t alphanumeric(char *);
uint8_t numeric(char *);
