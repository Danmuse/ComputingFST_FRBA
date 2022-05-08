/*
 * Tabla ASCII:
 * Numeros	48...57
 * Mayusculas 	65...90
 * Minusculas 	97...122
 */

#include <stdio.h>

int main(void){
  int i, MAY_start = 65, MAY_end = 90;
  // int j, MIN_start = 97, MIN_end = 122;
  // int k, NUM_start = 48, NUM_end = 57;
  printf("Despliega la tabla de codigo ASCII\n");
  printf("Decimal       Caracter");
  for (i = MAY_start; i <= MAY_end; i++)
  printf("\n%d     -      %c", i, i);
  printf("\n");
  return 0;
}
