#include <stdio.h>
#define CANT 3

int main() {
	int result = 0, buffer, i;

	// Ciclo FOR - Suma de valores
	printf("\nCiclo \"for\" Ingrese 3 numeros\n");
	for (i = 0; i < CANT; i++) {
		scanf("%d", &buffer);
		result += buffer;
	}
	printf("La suma resultante es %d\n", result);
	result = 0; i = 0;

	// Ciclo WHILE - Resta de valores
	printf("\nCiclo \"while\" Ingrese 3 numeros\n");
	while (i < CANT) {
		scanf("%d", &buffer);
		result -= buffer;
		i++;
	}
	printf("La resta resultante es %d\n", result);
	return 0;
}
