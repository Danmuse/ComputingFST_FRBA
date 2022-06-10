/*****************************************************************************************
 * Realice un programa que genere 100 valores aleatorios entre 10 y 20.                  *
 * Se debera informar al usuario el promedio, el valor maximo, minimo y el mas repetido. *
 *****************************************************************************************/

#include <stdio.h>
#include <stdlib.h>	// Incluye los prototipos de funcion para la generacion de numeros random
#include <sys/types.h>	// Busqueda y ordenamiento de directorios
#include <unistd.h>	// Incluye el prototipo de funcion "getpid(void)"
#define MAX 100

int main (void) {
	int i, j, random[MAX], acc = 0, max_value = 10, min_value = 20, max_count = 0, idem_counter = 0, idem_value = 0;
	float average = 0;
	srand(getpid());
	
	for (i = 0; i < MAX; i++) {
		random[i] = (rand() % 11) + 10;
		printf("%d%s", random[i], i % 5 < 4 ? "\t" : "\n");
		acc += random[i];
		if (random[i] > max_value) max_value = random[i];
		if (random[i] < min_value) min_value = random[i];
		for (j = 0; j < MAX; j++) {
			if (i != j) { if (random[i] == random[j]) idem_counter++; }
			else {
				if (idem_counter > max_count) {
					max_count = idem_counter;
					idem_value = random[j];
				}
				idem_counter = 1;
			}
		}
	}
	
	average = (float) acc / MAX;
	printf("\nDe los 100 valores aleatorios entre 10 y 20, se observa:\n");
	printf("Promedio: %.2f\nValor maximo: %d\nValor minimo: %d\n", average, max_value, min_value);
	printf("Numero mas repetido: %d \"%d\"\n", max_count, idem_value);
	return 0;
}
