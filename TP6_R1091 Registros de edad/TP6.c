/*
 * Desarrollar un programa que permita calcular la edad aproximada
 * de una persona. Para ello es necesario conocer el año actual en curso,
 * junto con el año de nacimiento de dicha persona y restarlas.
 * Considere validar que el año de nacimiento esté entre 1900 y 2017, 
 * Al terminar imprima el resultado obtenido. 
 */

#include <stdio.h>

int main (void){
int age, born, year = 2022;
printf("\nIngrese su fecha de nacimiento\n");
scanf("%d", &born);
if (born > 1900 && born < 2017){
age = year - born;
printf("\nSu edad es %d\n", age);
} else {
printf("\nDisculpe, no admitimos su edad\n");
}
return 0;
}
