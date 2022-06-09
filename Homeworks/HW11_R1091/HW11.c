/*****************************************************************************************
 * Realice un programa que genere 100 valores aleatorios entre 10 y 20.                  *
 * Se debera informar al usuario el promedio, el valor maximo, minimo y el mas repetido. *
 *****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>	// Incluye los prototipos de funcion para la generacion de numeros random
#include <sys/types.h>	// Busqueda y ordenamiento de directorios
#include <unistd.h>	// Incluye el prototipo de funcion "getpid(void)"
#define MAX 10

int main (void) {
	int i = 0, random[MAX], acc = 0, max_value = 0, min_value = 0;
	float average = 0;
	srand(getpid());
	
	for (i = 0; i < MAX; i++) {
		random[i] = (rand() % 11) + 10;
		printf("%d%s", random[i], i % 5 < 4 ? "\t" : "\n");
		acc += random[i];
		if (random[i] > max_value) max_value = random[i];
		if (random[i] < random[i - 1]) min_value = random[i];
	}
	average = (float) acc / MAX;
	printf("\nDe los 100 valores aleatorios entre 10 y 20, se observa:\n");
	printf("Promedio: %.2f\nValor maximo: %d\nValor minimo: %d\n", average, max_value, min_value);
	printf("Numero mas repetido: %d\n", 0);
	return 0;
}
