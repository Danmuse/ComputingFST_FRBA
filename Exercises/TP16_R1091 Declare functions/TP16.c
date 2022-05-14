#include <stdio.h>
void value(int);

int main (void){
	int x;
	printf("\nIngrese un numero:\t");
	scanf("%d", &x);
	value(x);
	return 0;
}

void value(int val) {
	val > 0 ? printf("El numero ingresado es positivo\n") :
	printf("El numero ingresado es negativo\n");
	return;
}
