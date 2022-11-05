#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*
 * Header de la libreria pthreads
 */
#include <pthread.h>

/*
 * Prototipos
 */
void *work(void *);
void print(char *);

/*
 * Variables Globales
 */
int contador = 0;

int main(int argc, char **argv) {
    /*
     * Definido en "sys/types.h" como "typedef unsigned int pthread_t"
     */
    pthread_t tid;
    int response;

    // getpid returns process ID from kernel
    fprintf(stderr, "Main:: pid [Process ID] is %d\n", getpid());
    // gettid returns thead ID from kernel
    fprintf(stderr, "Main:: tid [Thread ID] is %d\n", gettid());

    /*
     * int pthread_create(pthread_t *thread,
     * const pthread_attr_t *attr,
     * void *(*start_routine)(void*),
     * void *arg);
     */
    response = pthread_create(&tid, NULL, work, NULL);

    if (response != 0) {
    	// "stdout" as first parameter is correct as well
        fprintf(stderr, "Main :: No se pudo crear el thread.");
        exit(-1);
    }
    fprintf(stderr, "Main:: Fin\n");
    // Sincronize all processes with "pthread_exit". Don't use "return" in this case
    // It's not neccesary use "pthread_join" 'cause "pthread_exit" recopile all "pthread_joins"  
    pthread_exit(NULL);
}

void *work(void *p) {
    char s[80];
    // pthread_self returns thead ID from library
    sprintf(s, "Thread:: Hello World, pid %d thread id %ld\n", getpid(), pthread_self());
    print(s);
    pthread_exit(NULL);
}

void print(char *s) {
    while (s != NULL && *s != '\0') {
        fputc((int)*s, stderr);
        s++;
    }
    fputc('\n', stderr);
}
