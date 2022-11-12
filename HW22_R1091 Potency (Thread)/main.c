/*******************************************************************************************************************************
 Implementar un programa que calcule una secuencia de potencias de 2. El programa creara tantos hilos como se especifique en su
 unico argumento. Y cada hilo calculara la potencia de 2 de un numero que se le pasa como argumento. El primer hilo recibira 0
 como argumento y calculara 2^0. El segundo hilo, 2^1 El tercero, 2^2 y asi sucesivamente. El hilo principal mostrara por
 pantalla el resultado calculado por cada hilo subordinado.
 *******************************************************************************************************************************/
 
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define THREAD_NUM 2
#define BUFFER_MAX 10

int buffer[BUFFER_MAX];
int count = 0;
pthread_mutex_t mutexBuffer;

void *producer(void *args);
void *consumer(void *args);

int main(int argc, char *argv[]) {
    int index;
    pthread_t th[THREAD_NUM];

    srand(time(NULL));

    pthread_mutex_init(&mutexBuffer, NULL);

    for (index = 0; index < THREAD_NUM; index++) {
        if (index % 2 == 0) {
            if (pthread_create(&th[index], NULL, &producer, NULL) != 0)
                perror("Failed to create thread");
        }
        
        else {
            if (pthread_create(&th[index], NULL, &consumer, NULL) != 0)
                perror("Failed to create thread");
        }
    }
    
    for (index = 0; index < THREAD_NUM; index++) {
        if (pthread_join(th[index], NULL) != 0)
            perror("Failed to join thread");
    }
    
    pthread_mutex_destroy(&mutexBuffer);

    return EXIT_SUCCESS;
}

void *producer(void *args) {
    int x;
    while (1) {
        x = rand() % 100;

        // Add to the buffer
        pthread_mutex_lock(&mutexBuffer);
        if (count < BUFFER_MAX) {
            buffer[count] = x;
            count++;
        } // else printf("PRODUCER:: Skipped value\n");
        pthread_mutex_unlock(&mutexBuffer);
    }
}

void *consumer(void *args) {
    int y;
    while (1) {
        y = -1;

        // Remove from the buffer
        pthread_mutex_lock(&mutexBuffer);
        if (count > 0) {
            y = buffer[count - 1];
            count--;
        }
        pthread_mutex_unlock(&mutexBuffer);

        // Consume
        printf("Got %d\n", y);
    }
}
