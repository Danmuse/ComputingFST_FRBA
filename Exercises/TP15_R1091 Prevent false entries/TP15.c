#include <stdio.h>
#define CANT 5

int main (void){
	int i = 0, temp, accumulator = 0, output;
	float average;
	while (i < CANT) {
		printf("Ingrese Temp. #%d\n", i);
		output = scanf("%d", &temp);
		if (output != 1) {
			printf("Solo es posible ingresar numeros enteros\n");
			break;
		}
		accumulator += temp;
		i++;
	}
	average = (float) accumulator / i;	// "(float) k" convert the type of variable according to the argument
	printf("El promedio es %.2f\tDivisor: %d\tAcc.: %d\n", average, i, accumulator);
	return 0;
}
