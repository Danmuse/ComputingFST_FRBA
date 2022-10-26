// Un puntero de función es un tipo de datos cuyos valores oscilan entre los nombres de procedimiento.

#include <stdio.h>

int (*calc)(int, int);
int suma(int, int);
int resta(int, int);
int multi(int, int);
int division(int, int);

int main(void) {
	int result = 0;
	calc = suma;
	calc = resta;
	calc = multi;
	result = calc(2, 5);
	printf("El resultado es %d\n", result);
	return 0;
}

int suma(int a, int b) {
	return a + b;
}

int resta(int a, int b) {
	return a - b;
}

int multi(int a, int b) {
	return a * b;
}

int division(int a, int b) {
	return a / b;
}
