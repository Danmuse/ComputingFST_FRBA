/****************************************************************************
 * void array_fill(int *, int, int); Inicializa el array con el valor dado. *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 10
#define MAX 5

typedef u_int8_t uint8_t; // sizeof(uint8_t) = 1 Byte

void array_fill(int *, int, int);

int main (void) {
	uint8_t i, value, random[SIZE];
	int8_t input;
	srand(getpid());
	value = rand() % MAX;
	printf("\nrandom[?] = %u\n\n", value);
	for (i = 0; i < SIZE; i++) { 
		random[i] = rand() % MAX;
		printf("%u%s", random[i], i % 5 < 4 ? "\t" : "\n");
	}
	input = array_fill(...);
	input == -1 ? printf("\nNo se han encontrado coincidencias...\n\n") :
	printf("\nEn el siguiente indice se encuentra el valor dado: \nrandom[%d]\n\n", input);
	return 0;
}

void array_fill(int *, int, int) {
	
}
