/* Same Code Without Theads

#include <stdio.h>
#include <stdlib.h>

void work(void);

int main(int argc, char *argv[]) {
	work();
	return EXIT_SUCCESS;
}

void work() {
	printf("== Informatica 1 ==\n");
}

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void *work(); // Prototype

int main(int argc, char *argv[]) {
	pthread_t thread;
	pthread_create(&thread, NULL, work, NULL);
	pthread_join(thread, NULL); // IDEM: sleep(Since thread execute); 
	return EXIT_SUCCESS;
}

void *work() {
	printf("== Informatica 1 ==\n");
}
