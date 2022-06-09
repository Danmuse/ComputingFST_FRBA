/******************************************************************************
 * Realice un programa que genere 100 valores aleatorios entre 0 y 100;       *
 * y los guarde en un array.                                                  *
 * Solicite al usuario un numero y cuente cuantas veces aparece dicho numero. *
 ******************************************************************************/

#include <stdio.h>
#include <stdlib.h>	// Incluye los prototipos de funcion para la generacion de numeros random
#include <sys/types.h>	// Busqueda y ordenamiento de directorios
#include <unistd.h>	// Incluye el prototipo de funcion "getpid(void)"
#define MAX 100

int main (void) {
	int i, input, values[MAX], value = 0, equal_value = 0;
	srand(getpid());
	
	printf("\nIngrese un valor entre 0 y menor a 100: ");
	// Si "input" es 0, quiere decir que lo ingresado en scanf es distinto a un numero decimal
	// Si "input" es 1, quiere decir que lo ingresado en scanf es un numero decimal
	input = scanf("%d", &value);
	
	if (input == 0 || value >= 100) printf("El valor ingresado no es valido\n");
	
	else {
		for (i = 0; i < MAX; i++) {
			values[i] = rand() % 100;
			printf("%d%s", values[i], i % 5 < 4 ? "\t" : "\n");
			if (values[i] == value) equal_value++;
		}
		printf("\nDe los 100 valores aleatorios, hay %d \"%d\"\n", equal_value, value);
	}
	return 0;
}
