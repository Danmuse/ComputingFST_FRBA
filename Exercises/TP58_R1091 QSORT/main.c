#include <stdio.h>
#include <stdlib.h>

void swap(int*, int*);
int comp(int*, int*);

int main(void) {
	size_t i;
	int* data = {7, 1, 3, 5, 2, 8, 10}
	qsort(data, sizeof(int), sizeof(data) / sizeof(int), comp);
	for (i = 0; i < sizeof(data)/sizeof(int); i++) printf("data[%ld] = %d\n", i, data[i]);
	return 0;
}

int arr_

for (i = 0; i < (size -1); i++) {
	for(j = i + 1; j < size; j++) {
		// if (vec[i] < vec[j])  { 
			swap(&vec[i], &vec[j]);
			hubo_cambio = true;
		}
	}
	hubo_cambio = false;
}

void swap(int*, int*) {
	
}

int comp(int* a, int* b) {
	return *a > *b;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void swap(int *, int *);

void printArray(int *, int);

int compare(int *, int *);

#define ARRAY_SIZE 100000

int main() {
    int array[ARRAY_SIZE];
    int i;
    int j;

    srand(getpid());

    for (i = 0; i < ARRAY_SIZE; i++) array[i] = rand() % 20;
    qsort(array, ARRAY_SIZE, 4, compare);
//    for (i = 0; i < ARRAY_SIZE - 1; i++) {
//        for (int j = i + 1; j < ARRAY_SIZE; j++) {
//            if (array[i] < array[j]) swap(&array[i], &array[j]);
//        }
//    }
    printf("array:\n");
    printArray(array, ARRAY_SIZE);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; ++i) printf("Elem %d: %d\n", i, arr[i]);
}

int compare(int *a, int *b) {
    if (*a < *b) return 1;
    else if (*a == *b) return 0;
    return -1;
}

*/
