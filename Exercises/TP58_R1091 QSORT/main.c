/*

#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 7

typedef unsigned short int uint8_t;
typedef unsigned int uint16_t;

void swap(uint8_t*, uint8_t*);
int comp(int*, int*);
void printArray(uint8_t[], size_t);

int main(void) {
	size_t index, j_index;
	uint8_t data[ARRAY_SIZE] = {7, 1, 3, 5, 2, 8, 10}
	qsort(data, sizeof(int), sizeof(data) / sizeof(uint8_t), comp);
	// for (index = 0; index < ARRAY_SIZE - 1; index++) {
	//     for (j_index = index + 1; j_index < ARRAY_SIZE; j_index++)
	//          if (array[j_index] < array[j_index]) swap(&array[j_index], &array[j_index]);
	// }
	for (index = 0; index < sizeof(data)/sizeof(int); index++) printf("data[%ld] = %d\n", index, data[index]);
	return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int compare(int *a, int *b) {
    if (*a < *b) return 1;
    else if (*a == *b) return 0;
    return -1;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void swap(int *, int *);
void printArray(int *, int);
int compare(int *, int *);

#define ARRAY_SIZE 1000

int main(void) {
    int array[ARRAY_SIZE], index, j_index;

    srand(getpid());

    for (index = 0; index < ARRAY_SIZE; index++) array[index] = rand() % 20;
    qsort(array, ARRAY_SIZE, 4, (int *)compare);
    // for (index = 0; index < ARRAY_SIZE - 1; index++) {
    //     for (j_index = index + 1; j_index < ARRAY_SIZE; j_index++)
    //          if (array[j_index] < array[j_index]) swap(&array[j_index], &array[j_index]);
    // }
    printf("array: \n");
    printArray(array, ARRAY_SIZE);
    return EXIT_SUCCESS;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size) {
    size_t index;
    for (index = 0; index < size; ++index) printf("Elem %ld: %d\n", index, arr[index]);
}

int compare(int *a, int *b) {
    if (*a < *b) return 1;
    else if (*a == *b) return 0;
    return -1;
}
