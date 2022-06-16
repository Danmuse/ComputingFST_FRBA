/********************************************************************************************
 * int array_equal(int *, int, int *, int); Devuelve 1 si son iguales. -1 si son distintos. *
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define STATIC_SIZE 3
#define MAX 2 

typedef __UINT8_TYPE__ uint8_t; // sizeof(uint8_t) = 1 Byte

int8_t array_equal(uint8_t *, uint8_t, uint8_t *, uint8_t);

int main(void) {
	uint8_t i, SIZE = (uint8_t)STATIC_SIZE, random_FST[SIZE], random_SND[SIZE];
	int8_t input;
	srand(getpid());
	for (i = 0; i < SIZE * 2; i++) {
		if (i < SIZE) {
			if (i == 0) printf("\nPrimer arreglo:\n");
			random_FST[i] = rand() % MAX;
			printf("%u%s", random_FST[i], i % SIZE < SIZE - 1 ? "\t" : "\n");
		} else {
			if (i == SIZE) printf("\nSegundo arreglo:\n");
			random_SND[i] = rand() % MAX;
			printf("%u%s", random_SND[i], i % SIZE < SIZE - 1 ? "\t" : "\n");
		}
	}
	input = array_equal(random_FST, SIZE, random_SND, SIZE);
	input == -1 ? printf("\nLos arreglos no son iguales... %d\n\n", input) :
	printf("\nLos arreglos son iguales %d\n\n", input);
	return EXIT_SUCCESS;
}

int8_t array_equal(uint8_t *array_FST, uint8_t size_FST, uint8_t *array_SND, uint8_t size_SND) {
	int8_t output = 1;
	uint8_t i;
	if (size_FST == size_SND) {
		for (i = 0; i < size_FST; i++) {
			// if (*(array_FST + i) != *(array_SND + i)) { output = -1; break; }
			printf("%u\t", array_FST[i]);
			printf("%u\t", array_SND[i]);
		}
	} else output = -1;
	return output;
}
