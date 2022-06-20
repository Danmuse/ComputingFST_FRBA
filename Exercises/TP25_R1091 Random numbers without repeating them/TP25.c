/*****************************************************
 * Realice un programa que genere numeros aleatorios *
 * y muestre por pantalla los numeros sin repetirlos *
 *****************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 10
#define MAX 10

typedef __UINT8_TYPE__ uint8_t;
uint8_t checkRepeat(uint8_t, uint8_t *, int);

int main (void) {
	uint8_t i, random[10], num = 0;
	srand(getpid());
	if (SIZE == MAX) {
		for (i = 0; i < SIZE; i++) {
			while(checkRepeat(num, random, SIZE)) num = rand() % MAX + 1;
			random[i] = num;
			printf("%u%s", random[i], i % 5 < 4 ? "\t" : "\n");
		}
	} else return EXIT_FAILURE;
	return EXIT_SUCCESS;
}

uint8_t checkRepeat(uint8_t num, uint8_t *array, int size) {
	uint8_t i, buffer = 0;
	for (i = 0; i < size; i++) if (num == array[i]) buffer = 1;
	return buffer;
}
