#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef struct {
    pthread_t tid_th;
    long value_th;
    long result_th;    
} data_t;

void *work(void *);

int main(int argc, char **argv) {
    data_t st_data;
    st_data.tid_th = 0;
    st_data.value_th = 10;
    st_data.result_th = 0;
    
    if (pthread_create(&st_data.tid_th, NULL, work, (void *)&st_data) != 0) {
        // "stdout" as first parameter is correct as well
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }
    
    pthread_join(st_data.tid_th, NULL);
    printf("Result: %ld\n", st_data.result_th);
    fprintf(stderr, "Threads:: Fin\n");
    fprintf(stderr, "Main:: Fin\n");
    return EXIT_SUCCESS;
}

void *work(void *argument) {
    data_t *st = (data_t *)argument;
    st -> result_th = st -> value_th + 1;
    return NULL;
}
