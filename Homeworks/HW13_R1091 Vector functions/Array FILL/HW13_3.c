/****************************************************************************
 * void array_fill(int *, int, int); Inicializa el array con el valor dado. *
 ****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 10
#define MAX 50

typedef __UINT8_TYPE__ uint8_t; // sizeof(uint8_t) = 1 Byte on Ubuntu

void array_fill(uint8_t *, int, uint8_t);

int main(void) {
	uint8_t i, value, random[SIZE];
	srand(getpid());
	value = rand() % MAX;
	for (i = 0; i < SIZE; i++) { 
		random[i] = rand() % MAX;
		printf("%u%s", random[i], i % 5 < 4 ? "\t" : "\n");
	}
	printf("\nrandom[0] = %u\n", value);
	array_fill(random, SIZE, value);
	for (i = 0; i < SIZE; i++) { printf("%u%s", random[i], i % 5 < 4 ? "\t" : "\n"); }
	return EXIT_SUCCESS;
}

void array_fill(uint8_t *array, int size, uint8_t value) {
	uint8_t i;
	for (i = 0; i < size; i++) array[i] = value;
}
