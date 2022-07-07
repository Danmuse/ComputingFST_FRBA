/****************************************************************************************************
 * init_arr(int a[], int max_size) Inicializar todos los valores en '0'                             *
 * load_arr(int a[], int max_size) Ingreso por teclado hasta el max_size o hasta que se ingrese '0' *
 * size_arr(int a[], int max_size) Devuelve el tamaño del array                                     *
 * has_value(int a, int b[]) Buscar el valor de 'a' en 'b'                                          *
 * get_value(int a, int b[], int max_size) Inserta un elemento al final del array                   *
 * print_arr(int a[]) Muestra el array                                                              *
 * union_arrs(int a[], int b[], int c[], int max_size) Copia el array 'b' y 'c' en 'a'              *
 ****************************************************************************************************
 * NOTA: Se considera que toda posicion del arreglo que tiene un '0' no es un elemento del arr.     *
 * Un arreglo con TAMANO lleno con valores '0' se lo considera arr vacio.                           *
 ****************************************************************************************************/
 
#include <stdio.h>
#include "myString.h"

void init_arr(int a[], int max_size) {
	size_t i;
	for(i = 0; i < max_size; i++) a[i] = 0;
}

void load_arr(int a[], int max_size) {
	size_t i;
	printf("\nIngrese por el teclado los valores para cada elemento. Envie \"0\" para salir\n");
	for(i = 0; i < max_size; i++) {
		printf("arr[%li] = ", i);
		scanf("%d", a);
		if(*a == 0) break;
		else if(*a > 1000 || *a < -1000) break;
	}
}

void print_arr(int a[]) {
	size_t count = 0;
	printf("\nLos elementos del array son: \n");
	while(*a != 0 && *a <= 1000 && *a >= -1000) {
		printf("%d%s", *a, count % 5 < 4 ? "\t" : "\n");
		count++;
		a++;
	}
}
