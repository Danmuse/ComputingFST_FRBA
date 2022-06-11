/*********************************************************************************************
 * Realice un programa que genere un conjunto de 1000 numeros aleatorios entre 0 y 100.      *
 * Se debera informar al usuario el orden de aparicion de los siguientes numeros de interes: *
 * 0, 1, 10 y 100.                                                                           * 
 *********************************************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>	// Incluye los prototipos de funcion para la generacion de numeros random
#include <sys/types.h>	// Busqueda y ordenamiento de directorios
#include <unistd.h>	// Incluye el prototipo de funcion "getpid(void)"
#define MAX 1000

int main (void) {
	int i, random[MAX];
	u_int8_t j, pos[4], order[4], pos_order[4];
	char zero_init = 0, one_init = 0, ten_init = 0, hundred_init = 0;
	srand(getpid());
	
	for (i = 0; i < MAX; i++) {
		random[i] = rand() % 101;
		printf("%d%s", random[i], i % 5 < 4 ? "\t" : "\n");
		if (random[i] == 0 && zero_init == 0) { pos[0] = i; zero_init = 1; }
		if (random[i] == 1 && one_init == 0) { pos[1] = i; one_init = 1; }
		if (random[i] == 10 && ten_init == 0) { pos[2] = i; ten_init = 1; }
		if (random[i] == 100 && hundred_init == 0) { pos[3] = i; hundred_init = 1; }
	}
	
	for (i = 0; i < 4; i++) order[i] = pos[i];
	
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			short int x, y;
			x = order[i] - order[j];
			if (x < 0) {
				y = order[j];
				order[j] = order[i];
				order[i] = y;
			}
		}
	}
	
	for (i = 0; i < 4; i++) { 
		for (j = 0; j < 4; j++) { 
			if (pos[i] == order[j]) pos_order[i] = j + 1; 
		} 
	}
	
	for (i = 0; i < 4; i++) printf("%sLa primera posicion ocupada por \"%.0f\" es [%d] #%d\n",
	i == 0 ? "\n" : "", pow(10, i - 1), pos[i], pos_order[i]);
	return 0;
}
