#include <stdio.h>
#include <unistd.h> // "sleep(ms);" function
int chooseNum;

int main(void) {
printf("Tipea un numero (negativo o positivo): ");
scanf("%d", &chooseNum);
if(chooseNum > 0)
printf("El numero %d es positivo\n", chooseNum);
else if(chooseNum < 0)
printf("El numero %d es negativo\n", chooseNum);
else
printf("El numero %d es nulo\n\a", chooseNum);

return 0;
}
