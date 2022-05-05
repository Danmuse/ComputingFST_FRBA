/*
 * Desarrollar un programa que permita calcular el promedio de 3 notas.
 * Luego debe obtener la situación final que refleja el promedio, ya sea
 * aprobado o reprobado. Considere validar que las notas estén entre 1 y 7.
 * Al terminar imprima la situación junto con el promedio.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
float nota1, nota2, nota3, promedio;
printf("\nIngrese la primer calificacion del alumno\n");
printf("Procure ingresar una nota entre 1 y 7\n");
scanf("%f", &nota1);

printf("\nIngrese la segunda calificacion del alumno\n");
printf("Procure ingresar una nota entre 1 y 7\n");
scanf("%f", &nota2);

printf("\nIngrese la tercer calificacion del alumno\n");
printf("Procure ingresar una nota entre 1 y 7\n");
scanf("%f", &nota3);

// Con la siguiente condición se validarán las notas ingresadas,
// pudiendo aceptar unicamente valores entre 1 y 7.
// De lo contrario, se deberá ejecutar nuevamente el programa.

if (nota1 < 1 || nota1 > 7 || nota2 < 1 || nota2 > 7 || nota3 < 1 || nota3 > 7){
printf("\nLo sentimos, no hemos podido validar la nota. Vuelva a intentarlo\n");
exit(0);
}

promedio = (nota1 + nota2 + nota3)/3;

promedio >= 6 && promedio <= 7 ?
printf("\nAPROBADO, su calificacion es %.2f\n", promedio) :
printf("\nDESAPROBADO, su calificación es %.2f\n", promedio);
return 0;
}
