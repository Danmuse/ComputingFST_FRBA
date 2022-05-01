/*
 * Desarrollar un programa que permita calcular el valor de la función f(x)
 * para el valor de 𝑥 ingresado y muestre su resultado por pantalla.
 * f(x) = 3𝑥 + 2
 */

#include <stdio.h>

int main (void){
int x, result;
printf("\nIngrese un valor de 'x' para satisfacer a la función f(x) = 3x+2\n");
scanf("%d", &x);
result = 3*x+2;
printf("\nf(%d) = %d\n", x, result);
return 0;
}
