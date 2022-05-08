#include <stdio.h>

// Directivas de procesador: "#define"

#define VERDADERO 1  // "VERDADERO" es una constante
#define FALSO 0      // "FALSO" es una constante

// NOTA: Los numeros negativos como "-1" es VERDADERO.

int main(void){
  int h,z,a;
  h=3;
  z=5;

  // Imprime  0 (FALSO)
  printf("h=3 z=5 (h==1) \t\t==> %d\n", h == 1);

  // Imprime  1 (VERDADERO)
  printf("h=3 z=5 (h==3) \t\t==> %d\n", h == 3);

  // Imprime  5 (VERDADERO)
  printf("h=3 z=5 (z) \t\t==> %d\n", z );

  // Imprime  1 (VERDADERO)
  printf("h=3 z=5 (z>=h) \t\t==> %d\n", z >= h);

  // Imprime  0 (FALSO)
  printf("h=3 z=5 (h>=z) \t\t==> %d\n", h >= z);

  // Imprime  1 (VERDADERO)
  printf("h=3 z=5 (5<=z) \t\t==> %d\n", 5 <= z);

  // Imprime  0 (FALSO)
  printf("h=3 z=5 (5<z) \t\t==> %d\n", 5 < z);

  // Imprime  1 (VERDADERO)
  a= (h!=z); // O sin paréntesis
  printf("h=3 z=5 (a= (h!=z)) \t==> %d\n", a);

  // Imprime  0 (FALSO)
  a= h==z;
  printf("h=3 z=5 (a= h==z) \t==> %d\n", a);

  return 0;
}
