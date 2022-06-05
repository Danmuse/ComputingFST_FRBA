#include <stdio.h>
#define MAX 5

int main (void) {
	int i;
	float acc = 0, max_prom = 0, prom = 0;
	float values[MAX];
	
	while (1) {
	
		for (i = 0; i < MAX; i++) {
			printf("Valor #%i: ", i + 1);
			scanf("%f", &values[i]);
			acc += values[i];
		}
		
		prom = acc/MAX;
		printf("El promedio fue %.2f\n\n", prom);
		if (prom > max_prom) max_prom = prom;
		if (prom == 0) break;
		acc = 0;
	
	}
	
	printf("\nEl mayor promedio fue %.2f\n\n", max_prom);
	return 0;
}
