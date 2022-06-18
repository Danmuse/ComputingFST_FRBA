/********************************************************************************************
 * int array_equal(int *, int, int *, int); Devuelve 1 si son iguales. -1 si son distintos. *
 ********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE_FST 3
#define SIZE_SND 3
#define MAX 2

typedef __UINT8_TYPE__ uint8_t; // sizeof(uint8_t) = 1 Byte on Ubuntu
typedef __INT8_TYPE__ int8_t;

int8_t array_equal(uint8_t *, uint8_t, uint8_t *, uint8_t);

int main(void) {
	uint8_t i, random_FST[SIZE_FST], random_SND[SIZE_SND];
	int8_t input;
	srand(getpid());
	
	printf("\nPrimer arreglo:\n"); 
	for (i = 0; i < SIZE_FST; i++) {
		random_FST[i] = rand() % MAX;
		printf("%u%s", random_FST[i], i % 5 < 4 ? "\t" : "\n");
	}
	printf("\nSegundo arreglo:\n"); 
	for (i = 0; i < SIZE_SND; i++) {
		random_SND[i] = rand() % MAX;
		printf("%u%s", random_SND[i], i % 5 < 4 ? "\t" : "\n");
	}
	
	input = array_equal(random_FST, SIZE_FST, random_SND, SIZE_SND);
	input == -1 ? printf("\nLos arreglos no son iguales...\n\n") :
	printf("\nLos arreglos son iguales\n\n");
	return EXIT_SUCCESS;
}

int8_t array_equal(uint8_t *array_FST, uint8_t size_FST, uint8_t *array_SND, uint8_t size_SND) {
	int8_t output = 1;
	uint8_t i;
	if (size_FST == size_SND) {
		for (i = 0; i < size_FST; i++) if (*(array_FST + i) != *(array_SND + i)) { output = -1; break; }
	} else output = -1;
	return output;
}
