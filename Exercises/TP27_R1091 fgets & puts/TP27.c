// stdin (Keypad) - stdout (Monitor) - stderror (Monitor)
#include <stdio.h>
#define MAX 100

int main(void) {
	char str[MAX];
	printf("Ingrese su nombre: ");
	// scanf("%s", str);
	// printf("Hola \"%s\"\n\n", str);
	
	// fgets unicamente funciona con strings
	fgets(str, sizeof(str), stdin);
	puts(str); // Equivalente a 'printf("%s", str);'
	
	return 0;
}
