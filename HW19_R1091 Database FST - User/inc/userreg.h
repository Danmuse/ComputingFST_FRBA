#ifndef USERREG_H_
#define USERREG_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define STR_NAME 30

typedef __UINT8_TYPE__ uint8_t;
typedef __UINT16_TYPE__ uint16_t;

typedef struct {
	int ID;
	char name[STR_NAME];
	int age;
	float height;
	float weight;
} USER_st;

uint8_t chooseMenuOption(void);
bool checkEmptyFile(FILE *);
bool writeFile(FILE *, USER_st *, uint16_t);
bool loadFile(FILE *, USER_st *);
void clearBuffer(char *);

/*

void imprimirPersona(USER_st *);
int escribirPersonaEnArchivo(USER_st *, FILE *);
int leerPersonaPorId(FILE *, int, USER_st *);
int escribirArrayPersonasEnArchivo(USER_st[], int, FILE *);
int leerArrayDePersonasDeArchivo(FILE *, USER_st **);
void inicializarPersonaPorTeclado(USER_st *, int);
int buscarPersonaPorNombre(USER_st[], int, char *, USER_st *);
int editarEntradaConId(int, FILE *, USER_st *);

*/

#endif // USERREG_H_
