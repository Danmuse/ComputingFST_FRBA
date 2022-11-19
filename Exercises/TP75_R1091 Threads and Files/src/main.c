// Crear un thread que escribe "argv[2]" cantidad de lineas en un archivo de texto

// "<stdio.h>" "<stdlib.h>" "<stdbool.h>" "<string.h>" "<math.h>"
// "<fcntl.h>" "<pthread.h>" "<unistd.h>" "<sys/types.h>" "<sys/stat.h>"
// are included below...
#include "utils.h"

void *newLines(void *);

int main(int argc, char *argv[]) {
	pthread_t FST_thread;
	int argument = atoi(argv[1]);
	if (argc > 1) {
		if (pthread_create(&FST_thread, NULL, newLines, &argument)) {
			perror("Thread couldn't create...\n");
			exit(EXIT_FAILURE);
		}
		pthread_join(FST_thread, NULL);
		fprintf(stdout, "Thread:: Thread ends on success!!\n");
		return EXIT_SUCCESS;
	} else {
		fprintf(stderr, "Insert the amount lines to write next to executable\n");
		return EXIT_FAILURE;
	}
}

void *newLines(void *argument) {
	size_t index;
	const char path[] = "/home/ubuntu/Documents/TP75_R1091 Threads and Files/bin/Test.txt";
	const char buffer[] = "Nueva Linea\n";
	int fileDescriptor, maxLines = *((int *)argument);
	fileDescriptor = open(path, O_WRONLY | O_APPEND);
	if (fileDescriptor) perror("An error ocurred while opening File descriptor...\n");
	for (index = 0; index < maxLines; index++)
		if (write(fileDescriptor, buffer, sizeof(buffer) - 1) == -1) 
			perror("An error ocurred while writing File descriptor...\n");
	if (close(fileDescriptor)) perror("The File descriptor couldn't close correctly...\n");
}
