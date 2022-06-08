/*
 * Crear un programa que permita ingresar dos numeros y realizar la suma, resta, multiplicacion y division
 * entre estos dos valores al retornar una funcion que devuelva el resultado de cada operacion
 */

#include <stdio.h>
#include <stdlib.h>

int calc(int, int, int*, int*, int*, float*);

int main(void) {
	int result_suma, result_resta, result_mult; float result_div;
	int INPUT = calc(0, 0, &result_suma, &result_resta, &result_mult, &result_div);
	if (INPUT == 0) {
		printf("\nSuma: %d\nResta: %d\nMuliplicacion: %d\nDivision: %f\n\n",
		result_suma, result_resta, result_mult, result_div);
		return 0;
	} else {
		printf("\nSuma: %d\nResta: %d\nMuliplicacion: %d\nDivision: Lo sentimos, no es posible dividir por \"0\"\n\n",
	 	result_suma, result_resta, result_mult);
		return 0;
	}
}

int calc(int num1, int num2, int *suma, int *resta, int *mult, float *div){
	int output, debug = 0;
	printf("\nIngrese dos valores:\n");
	printf("#1 Valor: ");
	output = scanf("%d", &num1);
	printf("#2 Valor: ");
	output = scanf("%d", &num2);
	if (output != 1) {
		printf("\nSolo es posible ingresar numeros enteros\n\n");
		exit(0);
	}

	// --- *x --- es el contenido apuntado por "x"
	*suma = num1 + num2;
	*resta = num1 - num2;
	*mult = num1 * num2;
	*div = (float) num1 / num2;
	if (num2 == 0) debug = 1;
	return debug;
}
