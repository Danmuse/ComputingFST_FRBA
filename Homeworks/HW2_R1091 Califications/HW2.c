/* Diseñe un algoritmo para mostrar el mensaje APROBADO si la nota final
 * de un estudiante es mayor o igual que 6, y el mensaje DESAPROBADO
 * en caso contrario.
 */

#include <stdio.h>

int main (void){
float nota;
printf("\nIngrese la calificacion del alumno\n");
scanf("%f", &nota);
if (nota >= 6 && nota <= 10){
printf("\nAPROBADO\n");
} else if (nota >= 0 && nota < 6){
printf("\nDESAPROBADO\n");
} else {
printf("\nDebe insertar un numero del 0 al 10\n");
}
return 0;
}
