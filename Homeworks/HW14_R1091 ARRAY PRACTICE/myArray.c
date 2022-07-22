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
#include "myArray.h"

void init_arr(int a[], int max_size) {
	size_t i;
	for(i = 0; i < max_size; i++) a[i] = 0;
}

void load_arr(int a[], int max_size) {
	size_t i;
	printf("\nIngrese por el teclado los valores para cada elemento. Envie \"0\" para salir\n");
	while(1) {
		for(i = 0; i < max_size; i++) {
			printf("arr[%li] = ", i);
			scanf("%d", &a[i]); // Equal to "scanf("%d", a + i);"
			if(a[i] == 0) break;
			else if(a[i] > 1000 || a[i] < -1000) break;
		} if(*a != 0) break; // Se rompe al colocar una letra
	} 
}

void size_arr(int a[], int max_size) {
	size_t i;
	for(i = 0; i < max_size; i++) if(a[i] == 0) break;
	printf("\nEl tamanio del array es: %ld Elemento%c\n", i, i == 1 ? 0 : 115);
}

short int has_value(int a, int b[]) {
	size_t i;
	short int pos = -1;
	for(i = 0; *(b + i) != 0; i++) 
		if(b[i] == a) pos = i;
	return pos;
}

short int get_value(int a, int b[], int max_size) {
	size_t i;
	short int prompt = 0;
	for(i = 0; i < max_size; i++) {
		if(b[i] == 0) {
			b[i] = a;
			break;
		} else if(i == max_size - 1 && b[i] != 0) prompt = 1;
	}
	return prompt;
}

short int union_arrs(int a[], int b[], int c[], int max_size) {
	size_t i, arr_len = 0, arr2_len = 0;
	short int prompt = 0;
	for(i = 0; *(a + i) != 0; i++) arr_len++;
	for(i = 0; *(b + i) != 0; i++) arr2_len++;
	if(arr_len < max_size) {
		for(i = 0; arr_len + i < max_size; i++) {
			if(*(b + i) != 0) a[arr_len + i] = b[i];
			else a[arr_len + i] = c[i - arr2_len];
		}
	} else prompt = 1;
	return prompt;
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
