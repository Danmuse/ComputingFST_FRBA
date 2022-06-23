#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX 1000
#define SIZE 4

int main(void) {
	int i, j;
	int random[MAX];
	int pos[SIZE] = {0, 0, 0, 0};
	int numbers[SIZE] = {0, 1, 10, 100};
	srand(getpid());

	for(i=0; i < MAX; i++) {
        random[i] = rand() % 101;
	        for(j = 0; j < SIZE; j++) {
       		if(random[i] == numbers[j] && pos[j] == 0){
       			pos[j] = i;
	    	       	printf("La primera posicion ocupada por \"%d\" es [%d]\n", numbers[j], pos[j]);
			}
      		}
	}
	return EXIT_SUCCESS;
}
