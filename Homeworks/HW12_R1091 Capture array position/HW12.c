/*********************************************************************************************
 * Realice un programa que genere un conjunto de 1000 numeros aleatorios entre 0 y 100.      *
 * Se debera informar al usuario el orden de aparicion de los siguientes numeros de interes: *
 * 0, 1, 10 y 100.                                                                           * 
 *********************************************************************************************/

#include <stdio.h>
#include <stdlib.h>	// Incluye los prototipos de funcion para la generacion de numeros random
#include <sys/types.h>	// Busqueda y ordenamiento de directorios
#include <unistd.h>	// Incluye el prototipo de funcion "getpid(void)"
#define MAX 1000

int main (void) {
	int i, zero_pos, one_pos, ten_pos, hundred_pos, random[MAX];
	u_int8_t zero_init = 0, one_init = 0, ten_init = 0, hundred_init = 0;
	srand(getpid());
	
	for (i = 0; i < MAX; i++) {
		random[i] = rand() % 101;
		printf("%d%s", random[i], i % 5 < 4 ? "\t" : "\n");
		if (random[i] == 0 && zero_init == 0) { zero_pos = i; zero_init = 1; }
		if (random[i] == 1 && one_init == 0) { one_pos = i; one_init = 1; }
		if (random[i] == 10 && ten_init == 0) { ten_pos = i; ten_init = 1; }
		if (random[i] == 100 && hundred_init == 0) { hundred_pos = i; hundred_init = 1; }
	}
	
	printf("\nLa primera posicion ocupada por \"0\" es [%d]\n", zero_pos);	
	printf("La primera posicion ocupada por \"1\" es [%d]\n", one_pos);	
	printf("La primera posicion ocupada por \"10\" es [%d]\n", ten_pos);	
	printf("La primera posicion ocupada por \"100\" es [%d]\n", hundred_pos);	
	return 0;
}
