#include <stdio.h>
#include <stdlib.h>
#define ARR_SIZE 3
#define STR_LEN 20

/* RESUMEN: Pasaje de arrays a funciones
 * Los array a una función se pasan por referencia (dirección), en vez de
 * por valor como con las variables simples, esto es así, porque seria
 * muy ineficiente copiar todos los valores de los componentes de un
 * array para pasarlos por valor.
 * El pasaje por referencia implica, que en vez de copiar el array,
 * se pasa su dirección de comienzo
 * Esta dirección de comienzo, coincide con la dirección del nombre del
 * array, o lo que es lo mismo, con la dirección del primer elemento
 * A partir de esa dirección inicial (nombre del array), se encuentran
 * consecutivamente uno a continuación de otro, todos los elementos
 * del array. Como todos los elementos del array son del mismo tipo
 * (ocupan igual cantidad de bytes), los subsiguientes elementos se
 * encuentran sumando un valor fijo a la direccion del elemento
 * anterior, así hasta el ultimo.
 * A una función además de pasarle la dirección de comienzo del array,
 * hay que pasarle los límites del array, ya que el lenguaje C no
 * comprueba estos limites
 * El pasaje de un array multidimensional como argumento requiere el
 * pasaje de todas excepto la primera dimensión
 */

typedef __UINT8_TYPE__ uint8_t;
void arr_str_to_print(char [][STR_LEN], int);
void test(char **, int, int);

int main(void) {
	char arr_1[ARR_SIZE][STR_LEN] = {
		"Daniel 2", 
		"Juan 2", 
		"Carlos 2"
	};
	char arr_2[][STR_LEN] = {
		"Daniel 3", 
		"Juan 3", 
		"Carlos 3"
	};
	puts(*(arr_1 + 1) + 2); // "an 2"
	puts(arr_2[0]); // "Daniel 3"
	
	arr_str_to_print(arr_1, ARR_SIZE);
	arr_str_to_print(arr_2, ARR_SIZE);
	
	return EXIT_SUCCESS;
}

// El pasaje de un array multidimensional como argumento requiere el pasaje de
// todas EXCEPTO la primera dimension
void arr_str_to_print(char ptr[][STR_LEN], int size) { // size = ARR_SIZE
	uint8_t i = 0;
	// Notar que STR_LEN es necesario para el ajuste de puntero con ptr[i],
	// los saltos son cada STR_LEN cuando incremento en i
	for(i = 0; i < size; i++) printf("string [%d]: %s\n", i, ptr[i]);
}

// El compilador permite recibir 'char (*)[20]' por lo tanto la siguiente función retornara ERROR
/* void test(char **ptr, int a, int b) {
 	return;
} */
