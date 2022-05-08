#include <stdio.h>

/* ¿Qué sucede cuando asignamos un caracter a una variable char?
 * ¿Qué dato se guarda en la variable?
 * ¿Quien realiza esa conversión?
 */

int main(void) {
  int diference = 0;
  char letter_01 = 'a';
  char letter_02 = 97;  // No es posible almacenar numeros superiores a su tamaño (1 byte - 255)

  // Comparamos los dos caracteres para saber si son iguales
  // Para ello utilizamos el "operador arimético resta"

  diference = letter_01 - letter_02;
  printf("La diferencia es %d\n", diference);
  printf("int: %ld, float: %ld, double: %ld, char: %ld\n",
  sizeof(int), sizeof(float), sizeof(double), sizeof(char));
  return 0;
}
