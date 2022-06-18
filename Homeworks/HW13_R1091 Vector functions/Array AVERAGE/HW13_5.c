/**********************************************************
 * float array_average(int *, int); Devuelve el promedio. *
 **********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 10
#define MAX 10

typedef __UINT8_TYPE__ uint8_t; // sizeof(uint8_t) = 1 Byte on Ubuntu

float array_average(uint8_t *, int);

int main(void) {
	uint8_t i, random[SIZE];
	float input;
	srand(getpid());
	for (i = 0; i < SIZE; i++) { 
		random[i] = rand() % MAX;
		printf("%u%s", random[i], i % 5 < 4 ? "\t" : "\n");
	}
	input = array_average(random, SIZE);
	printf("\nPromedio: %.2f\n", input);
	return EXIT_SUCCESS;
}

float array_average(uint8_t *array, int size) {
	uint8_t i;
	short acc;
	float output;
	for (i = 0; i < size; i++) acc += array[i];
	output = (float) acc / size;
	return output;
}
