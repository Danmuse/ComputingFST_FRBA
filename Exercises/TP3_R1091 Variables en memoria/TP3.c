#include <stdio.h>

int main(void) {
int value = 99;
printf("\nEl valor 'value' es %d", value);
printf("\nLa dirección de 'value' es %p \n", &value);
// %p define el formato, imprime direcciones o punteros.
return 0;
}


