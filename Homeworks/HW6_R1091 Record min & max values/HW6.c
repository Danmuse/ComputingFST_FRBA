/*  Escriba un programa que reciba numeros del usuario y vaya presentando
 *  por pantalla el acumulado de todos los numeros ingresados. Al finalizar,
 *  presentar el mayor y el menor numero recibido. El ingreso finaliza cuando
 *  se recibe un numero negativo.
 */

#include <stdio.h>
#define TRUE 1

int main(void) {
	int input, output, min_buffer = 0, max_buffer = 0;
	printf("\nA continuacion se le pedira que registre algunos numeros.");
	printf("\nPara salir ingrese algun numero negativo");
	printf("\n\nIngrese numeros aleatorios: \n");
	while (TRUE) {
		output = scanf("%d", &input);
		if (output != 1) {
			printf("Solo es posible ingresar numeros enteros\n");
			break;
		}
		if (input >= 0) {
			min_buffer = max_buffer;
			if (input > max_buffer) max_buffer = input;
			else min_buffer = input;
		} else break;
	}
	printf("\nEl mayor numero ingresado fue %d", max_buffer);
	printf("\nEl menor numero ingresado fue %d\n", min_buffer);
	return 0;
}
