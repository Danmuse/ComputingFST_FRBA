#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *FST_work(void *argument);

int main(int argc, char **argv) {
    pthread_t FST_tid;
    long FST_value = 1, *result;

    // getpid returns process ID from kernel
    fprintf(stderr, "Main:: pid [Process ID] is %d\n", getpid());
    // gettid returns thead ID from kernel
    fprintf(stderr, "Main:: tid [Thread ID] is %d\n", gettid());

    if (pthread_create(&FST_tid, NULL, FST_work, (void *)&FST_value) != 0) {
        // "stdout" as first parameter is correct as well
        fprintf(stderr, "Main:: No se pudo crear el thread.");
        exit(-1);
    }
    
    // El segundo parametro es lo devuelto por el POSIX Thread
    pthread_join(FST_tid, (void **)&result);
    fprintf(stderr, "Thread:: result = %ld\n", *result);
    fprintf(stderr, "Threads:: Fin\n");
    free(result);
    fprintf(stderr, "Main:: Fin\n");
    return EXIT_SUCCESS;
}

/* Segmentation Fault!! "accumulador" will die after finish the thread

void *FST_work(void *argument) {
    long *value = (long *)argument;
    long index, accumulator = 0;
    for (index = 0; index < 1000000000; index++)
    	accumulator += *value;
    printf("First Thread:: Value is %ld\n", *value);
    return &accumulator;
}

*/

void *FST_work(void *argument) {
    long *value = (long *)argument;
    long index, accumulator = 0, *result;
    result = (long *)malloc(sizeof(long));
    for (index = 0; index < 1000000000; index++)
    	accumulator += *value;
    printf("First Thread:: Value is %ld\n", *value);
    *result = accumulator;
    return (void *)result;
}
