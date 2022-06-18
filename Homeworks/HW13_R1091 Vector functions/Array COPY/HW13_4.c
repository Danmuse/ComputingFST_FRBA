/******************************************************************************************************************
 * int array_copy(int *, int, int *, int); Copia un array en otro. -1 en caso de que los tamaños no sean iguales. *
 ******************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE_FST 5
#define SIZE_SND 5
#define MAX 10

typedef __UINT8_TYPE__ uint8_t; // sizeof(uint8_t) = 1 Byte on Ubuntu
typedef __INT8_TYPE__ int8_t;

int8_t array_copy(uint8_t *, uint8_t, uint8_t *, uint8_t);

int main(void) {
	uint8_t i, random_FST[SIZE_FST], random_SND[SIZE_SND];
	int8_t input;
	srand(getpid());
	
	printf("\nPrimer arreglo:\n"); 
	for (i = 0; i < SIZE_FST; i++) {
		random_FST[i] = rand() % MAX;
		printf("%u%s", random_FST[i], i % 5 < 4 ? "\t" : "\n");
	}
	
	input = array_copy(random_FST, SIZE_FST, random_SND, SIZE_SND);
	if (input == 0) {
		printf("\nSegundo arreglo:\n"); 
		for (i = 0; i < SIZE_SND; i++) printf("%u%s", random_SND[i], i % 5 < 4 ? "\t" : "\n");
	}
	else printf("\nEl tamaño de los arreglos son distintos...\n\n");
	return EXIT_SUCCESS;
}

int8_t array_copy(uint8_t *array_FST, uint8_t size_FST, uint8_t *array_SND, uint8_t size_SND) {
	int8_t output = 0;
	uint8_t i;
	if (size_FST == size_SND) {
		for (i = 0; i < size_FST; i++) array_SND[i] = array_FST[i];
	} else output = -1;
	return output;
}
