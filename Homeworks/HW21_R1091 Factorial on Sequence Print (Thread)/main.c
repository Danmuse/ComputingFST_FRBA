/*******************************************************************************************************************************
 Implementar un programa en C que calcule el factorial de los numeros que se le pasan como argumentos desde la linea de comandos
 El programa creara tantos hilos como argumentos se introduzcan y cada uno de los hilos recibira uno de esos argumentos y
 calculara su factorial. Retornar en orden cada uno de los threads.
 *******************************************************************************************************************************/
 
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 100

void *calculateFactorial(void *);

int main(int argc, char *argv[]) {
    int index, j_index;
    int *factorial;

    pthread_t threadIds[MAX_THREADS]; // NOT HANDLED SEGMENTATION FAULT
    
    if (argc == 1) perror("Insert an argument next to the execute\n");

    for (index = 1; index < argc; ++index)
	if (pthread_create(&threadIds[index - 1], NULL, calculateFactorial, (void *)argv[index])) 
            perror("Failed to create thread\n");
            
    for (j_index = 1; j_index < argc; ++j_index) {
        pthread_join(threadIds[j_index - 1], (void **)&factorial);
        printf("[Thread %lud] Factorial de %s es: %u\n",threadIds[j_index - 1], argv[j_index], *factorial);
    }
}


void *calculateFactorial(void *arg) {
    int index;
    __uint32_t *factorial = malloc(sizeof(__uint32_t));
    *factorial = 1;

    for (index = 1; index <= atoi((char *)arg); index++)
        *factorial *= index;
    return factorial;
}
