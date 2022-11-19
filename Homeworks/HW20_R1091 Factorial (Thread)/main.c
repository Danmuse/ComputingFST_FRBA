/*******************************************************************************************************************************
 Implementar un programa en C que calcule el factorial de los numeros que se le pasan como argumentos desde la linea de comandos
 El programa creara tantos hilos como argumentos se introduzcan y cada uno de los hilos recibira uno de esos argumentos y
 calculara su factorial. No importa que se mezcle la salida que imprimen los hilos.
 *******************************************************************************************************************************/
 
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define MAX_THREADS 100

void *calculateFactorial(void *);

int main(int argc, char *argv[]) {
    int index;
    pthread_t threadIds[MAX_THREADS]; // NOT HANDLED SEGMENTATION FAULT

    if (argc == 1) perror("Insert an argument next to the execute\n");

    for (index = 1; index < argc; ++index)
        if (pthread_create(&threadIds[index], NULL, calculateFactorial, (void *)argv[index])) 
            perror("Failed to create thread\n");
    pthread_exit(NULL);
    return EXIT_SUCCESS;
}


void *calculateFactorial(void *arg) {
    int index;
    __uint32_t factorial = 1;
    for (index = 1; index <= atoi((char *)arg); index++)
        factorial *= index;
    fprintf(stdout, "Factorial de %s arg es: %u\n", (char *)arg, factorial);
    return NULL;
}
