/*
 * Desarrollar un programa que permita calcular el área de un triángulo.
 * Recuerde que la fórmula a utilizar es: area= (base*altura)/2,
 * además valide que la base y la altura sean mayores a cero.
 * Al terminar imprima el resultado obtenido.
 */

#include <stdio.h>

int main (void){
float area, base, altura;
printf("\nInserte la base del triangulo:\n");
scanf("%f", &base);
printf("\nInserte la altura del triangulo:\n");
scanf("%f", &altura);
if (base > 0 && altura > 0){
area = (base*altura)/2;
printf("\nArea = (%.2f * %.2f)/2", base, altura);
printf("\nArea = %.2f\n", area);
} else {
printf("\nAmbas variables deben ser mayores a cero para satisfacer la ecuacion\n");
}
return 0;
}
