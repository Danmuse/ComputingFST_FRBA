#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  int i;
  //Ingrese una contraseña

  for (i = 0; i < 3; i++) {
    char password[1024] = {0};
    printf("Por favor, introduzca su contraseña: ");
    scanf("%s", &password);

    // strcmp se utiliza para comparar el tamaño de acuerdo con el orden de caracteres

    if (strcmp(password, "369369") == 0) {
      printf("¡Inicio de sesión exitoso!\n");
      break;
    } else
    printf("Su entrada es incorrecta, ¡intente nuevamente!\n");
  }

  if (i == 3) {
    printf("¡Has ingresado incorrectamente tres veces!\n");
  }

  return 0;
}
