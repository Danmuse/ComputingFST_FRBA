/* Without Thread

#include <stdio.h>
#include <stdlib.h>

void *FST_work(void *argument);
void *SND_work(void *argument);

int main(int argc, char **argv) {
    long FST_value = 1, SND_value = 20;

    // getpid returns process ID from kernel
    fprintf(stderr, "Main:: pid [Process ID] is %d\n", getpid());
    // gettid returns thead ID from kernel
    fprintf(stderr, "Main:: tid [Thread ID] is %d\n", gettid());

    FST_work(&FST_value);
    SND_work(&SND_value);
    
    fprintf(stderr, "Main:: Fin\n");
    return 0;
}

void *FST_work(void *argument) {
    long *value = (long *)argument;
    long index, accumulator = 0;
    for (index = 0; index < 1000000000; index++) {
    	accumulator = index;
    }
    printf("First Thread:: Value is %ld\n", *value);
    return NULL;
}

void *SND_work(void *argument) {
    long *value = (long *)argument;
    long index, accumulator = 0;
    for (index = 0; index < 1000000000; index++) {
    	accumulator = index;
    }
    printf("Second Thread:: Value is %ld\n", *value);
    return NULL;
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

void *FST_work(void *argument);
void *SND_work(void *argument);

int main(int argc, char **argv) {
    pthread_t FST_tid, SND_tid;
    long FST_value = 1, SND_value = 20;

    // getpid returns process ID from kernel
    fprintf(stderr, "Main:: pid [Process ID] is %d\n", getpid());
    // gettid returns thead ID from kernel
    fprintf(stderr, "Main:: tid [Thread ID] is %d\n", gettid());

    if (pthread_create(&FST_tid, NULL, FST_work, (void *)&FST_value) != 0) {
        // "stdout" as first parameter is correct as well
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }
    
    if (pthread_create(&SND_tid, NULL, SND_work, (void *)&SND_value) != 0) {
        // "stdout" as first parameter is correct as well
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }
    
    pthread_exit(NULL);
    fprintf(stderr, "Threads:: Fin\n");
}

void *FST_work(void *argument) {
    long *value = (long *)argument;
    long index, accumulator = 0;
    for (index = 0; index < 1000000000; index++)
    	accumulator += *value;
    printf("First Thread:: Value is %ld\n", *value);
    return NULL;
}

void *SND_work(void *argument) {
    long *value = (long *)argument;
    long index, accumulator = 0;
    for (index = 0; index < 1000000000; index++)
    	accumulator += *value;
    printf("Second Thread:: Value is %ld\n", *value);
    return NULL;
}
