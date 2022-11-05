#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

typedef void(*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);

int main(int argc, char *argv[]) {
	if (argc < 2) {
		printf("Error de argumentos\nUso: noint [nro-senial]\n");
		exit(EXIT_FAILURE);
	}
	/* Modificamos el handler de la señal recibida como argumento, por otro al que ignore */
	if (signal(atoi(argv[1]), SIG_IGN) == SIG_ERR) {
		printf("Error al trapear la senial %d\n", atoi(argv[1]));
		exit(EXIT_FAILURE);
	}
	while(1) sleep(1);
	return EXIT_SUCCESS;
}
