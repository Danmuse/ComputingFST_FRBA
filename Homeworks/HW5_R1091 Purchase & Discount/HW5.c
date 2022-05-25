/*
 * Desarrollar un programa que permita pedir por pantalla una cantidad de
 * metros cuadrados y luego el costo del metro cuadrado.
 * La cantidad de metros debe estar entre 1 y 100, mientras que el
 * costo del metro cuadrado debe estar entre $100 y $5.000.
 * Imprima el total aplicando un 5% de descuento sobre el neto (cantidad * costo)
 */

#include <stdio.h>
#include <stdlib.h>

int main (void){
int m2, costo_m2, neto;
float total;
printf("\n¿Cuantos metros cuadrados necesita?\n");
scanf("%d", &m2);
if (m2 < 1 || m2 > 100){
printf("Lo sentimos, solo brindamos unidades de hasta 100m2\n");
exit(0);
}
printf("¿Cual es el precio del metro cuadrado?\n$");
scanf("%d", &costo_m2);
if (costo_m2 < 100){
printf("Lo sentimos, el costo por metro cuadrado deberia exceder los $100\n");
exit(0);
} else if (costo_m2 > 5000){
printf("Lo sentimos, el costo por metro cuadrado no deberia exceder los $5000\n");
exit(0);
}
neto = m2 * costo_m2;
total = neto - (neto * 0.05);
printf("\nAqui tiene su recibo\n$%d +5%c desc. = $%.2f\nGracias por su compra\n", neto, 37, total);
return 0;
}
