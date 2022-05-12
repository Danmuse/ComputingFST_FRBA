#include <stdio.h>

int main (void){
  unsigned int output, day, month, year;
  float temp;

  // TEMP 23-04-2021 20.3     ==> OK
  // TEMP 23-04/2021 20.3     ==> ERROR
  // scanf espera a recibir el texto "TEMP" ingresado por teclado.
  printf("A continuacion se le solicita la fecha y temperatura: [TEMP DD-MM-AAAA temp.]\n");
  output = scanf("TEMP %u-%u-%u %f", &day, &month, &year, &temp);
  output != 4 ? printf("ERROR. Verifique el texto ingresado y vuelva a intentarlo.\n") :
  printf("El dia %u-%u-%u se registro una temperatura de %.2f°C\n", day, month, year, temp);
  return 0;
}

  // CONCLUSIÓN:

  // "output" valida la cantidad de datos que fueron ingresados con éxito
  // Si "output = 4" entonces la sintaxis y el valor de los 4 datos ingresados son CORRECTOS
  // Si "output = 0" entonces la sintaxis y el valor de los 4 datos ingresados son INCORRECTOS

