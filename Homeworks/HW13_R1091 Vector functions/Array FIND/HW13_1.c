/*************************************************************************************************
 * int array_find(int *, int, int); Devuelve el indice del elemento dado. -1 si no lo encuentra. *
 *************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 10
#define MAX 5

typedef u_int8_t uint8_t; // sizeof(uint8_t) = 1 Byte

int8_t array_find(uint8_t *, int, uint8_t);

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
	input = array_find(random, SIZE, value);
	input == -1 ? printf("\nNo se han encontrado coincidencias...\n\n") :
	printf("\nEn el siguiente indice se encuentra el valor dado: \nrandom[%d]\n\n", input);
	return 0;
}

int8_t array_find(uint8_t *array, int size, uint8_t index) {
	uint8_t i;
	int8_t output = 0;
	for (i = 0; i < size; i++) {
		if (array[i] == index) output = i;
		else if (output == 0) output = -1;
	} 
	if (array[0] == index && output == -1) output = 0;
	return output;
}
