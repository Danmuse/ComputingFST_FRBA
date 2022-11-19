/*******************************************************************************************************************************
 Implementar un programa que calcule una secuencia de potencias de 2. El programa creara tantos hilos como se especifique en su
 unico argumento. Y cada hilo calculara la potencia de 2 de un numero que se le pasa como argumento. El primer hilo recibira 0
 como argumento y calculara 2^0. El segundo hilo, 2^1 El tercero, 2^2 y asi sucesivamente. El hilo principal mostrara por
 pantalla el resultado calculado por cada hilo subordinado.
 *******************************************************************************************************************************/
 
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define MAXTHREADS 100

void *calculatePowerOf2(void *);

int main(int argc, char *argv[]) {
    int index, j_index, *power, *currPow;
    pthread_t threadIds[MAXTHREADS]; // NOT HANDLED SEGMENTATION FAULT

    if (argc > 1) {
   	 for (index = 0; index < atoi(argv[1]); ++index) {//NOT HANDLED EXCEPTION
   	     currPow = malloc(sizeof(int));
    	     *currPow = index;
    	     if (pthread_create(&threadIds[index], NULL, calculatePowerOf2, (void *)currPow) != 0)
                 perror("Failed to create thread\n");
    	}

    	for (j_index = 0; j_index < atoi(argv[1]); ++j_index) {
            pthread_join(threadIds[j_index], (void **)&power);
            printf("[Thread %lud] 2 ^ %d = %d\n", threadIds[j_index], j_index, *((__uint32_t *)power));
        }
    	return EXIT_SUCCESS;
    } else perror("Insert an argument next to the execute\n");
}


void *calculatePowerOf2(void *power) {
    __uint32_t *result = malloc(sizeof(__uint32_t));
    *result = pow(2, *((__uint32_t *)power));
    free(power);
    return result;
}
