/*
 * Desarrollar un programa que permita pedir por pantalla el costo neto de un
 * producto.
 * Calcule el iva (21% * neto) y luego determine el total (neto + iva).
 * Valide que el costo neto sea mayor o igual que $10.000
 * Imprima todos los valores
 */

#include <stdio.h>

int main (void){
int neto; 
float iva, total;
printf("Coloque el costo neto del producto: \n");
scanf("%d", &neto);
iva = 0.21 * neto;
total = neto + iva;
if (neto >= 10000) {
printf("El costo neto es %d\n", neto);
printf("El costo iva es %.2f\n", iva);
printf("El costo total es %.2f\n", total);
} else {
printf("El monto ingresado no es suficiente\n");
}
return 0;
} 
