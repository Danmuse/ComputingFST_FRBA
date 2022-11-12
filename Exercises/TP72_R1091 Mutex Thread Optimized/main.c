/**************************
 ***** RACE CONDITION *****
 **************************/
 
// Race Condition es una vulnerabilidad que ocurre cuando un sistema 
// que maneja tareas en una secuencia específica es forzado a realizar 
// dos o más operaciones simultáneamente.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

// It could be a FILE, unsigned char, or whatever you want...
int shared_resource = 0;

// Devuelve el recurso compartido
int read_shared_resource(void);
// Cambiar el recurso compartido
void write_shared_resource(int value);

// Define mutex to avoid RACE CONDITION
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *work(void *);

int main(int argc, char **argv) {
    pthread_t FST_tid, SND_tid;
    int FST_value = 100, SND_value = 200; 
    
    if (pthread_create(&FST_tid, NULL, work, (void *)&FST_value) != 0) {
        // "stdout" as first parameter is correct as well
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }
    
    if (pthread_create(&SND_tid, NULL, work, (void *)&SND_value) != 0) {
        // "stdout" as first parameter is correct as well
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }
    
    pthread_join(FST_tid, NULL);
    pthread_join(SND_tid, NULL);
    printf("Main:: Valor %d\n", read_shared_resource());
    fprintf(stderr, "Threads:: Fin\n");
    fprintf(stderr, "Main:: Fin\n");
    return EXIT_SUCCESS;
}

void *work(void *argument) {
    int value;
    
    pthread_mutex_lock(&mutex);
    /* WARNING ZONE - RACE CONDITION */
    value = read_shared_resource();
    value += *(int *)argument;
    write_shared_resource(value);
    /*********************************/
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

// Devuelve el recurso compartido
int read_shared_resource(void) {
	usleep(250000); // Trying to produce RACE CONDITION
	return shared_resource;
}

// Cambiar el recurso compartido
void write_shared_resource(int value) {
	usleep(250000); // Trying to produce RACE CONDITION
	shared_resource = value;
}
