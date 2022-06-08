#include <stdio.h>
#include <stdlib.h>	// Incluye los prototipos de funcion para la generacion de numeros random
#include <sys/types.h>	// Busqueda y ordenamiento de directorios
#include <unistd.h>	// Incluye el prototipo de funcion "getpid(void)"
#define MAX 100

int main (void) {
	int i, a, buffer = 0;
	srand(getpid());
	
	for (i = 0; i < MAX; i++) {
		a = rand() % 100;
		printf("%d%s", a, i % 5 < 4 ? "\t" : "\n");
		if (a == 3) buffer++;
	}
	
	printf("\nDe los 100 valores solo hay %d \"3\"\n", buffer);
	return 0;
}
