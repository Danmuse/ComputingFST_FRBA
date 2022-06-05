#include <stdio.h>
#define MAX 5

// --- Metodo con vectores de enteros --- //

int main (void) {
	int i, value_1, value_2, value_3, value_4, value_5, pos = 0, MAYOR = 0;
	int buffer = 0;
	int *buffer_memory;
	int *values[] = { &value_1, &value_2, &value_3, &value_4, &value_5 };
	float prom = 0;
	
	for (i = 0; i < MAX; i++) {
		printf("Valor #%i: ", i + 1);
		scanf("%d", values[pos]);
		pos++;
	}
	
	prom = (float) (value_1 + value_2 + value_3 + value_4 + value_5) / MAX;
	printf("\nEl promedio es %.2f\n", prom);
	pos = 0;
	
	for (i = 0; i < MAX; i++) {
		buffer_memory = values[pos];
		buffer = *buffer_memory;
		if (buffer > prom) MAYOR++;
		buffer = 0;
		pos++;
	}
	
	printf("La cantidad de valores mayores al promedio son %d\n", MAYOR);
	return 0;
}

// --- Metodo con arrays --- //

/******************************

int main (void) {
	int i, values[MAX], acc = 0, MAYOR = 0;
	float prom = 0;
	
	for (i = 0; i < MAX; i++) {
		printf("Valor #%i: ", i + 1);
		scanf("%d", &values[i]);
		acc += values[i];
	}
	
	prom = (float) acc / MAX;
	printf("\nEl promedio es %.2f\n", prom);
	
	for (i = 0; i < MAX; i++) {
		if (values[i] > prom) MAYOR++;
	}
	
	printf("La cantidad de valores mayores al promedio son %d\n", MAYOR);
	return 0;
}

******************************/
