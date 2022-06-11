/************************************************************************************
 * Devuelve de la misma manera la posicion de memoria de los elementos de un vector *
 ************************************************************************************/

#include <stdio.h>

int main (void) {
	int i, x[] = {1, 3, 9, 12, 15};
	for (i = 0; i < 5; i++) {
		printf("%d %d %p\n", i, x[i], &x[i]);
		printf("%d %d %p\n\n", i, *(x + i), (x + i));
	}
	return 0;
}
