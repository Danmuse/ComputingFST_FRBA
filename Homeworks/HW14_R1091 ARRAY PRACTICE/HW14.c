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
#define SIZE 10

int main(void) {
	int arr[SIZE];
	init_arr(arr, SIZE);
	load_arr(arr, SIZE);
	size_arr(arr, SIZE);
	print_arr(arr);
	while(1) {
		short unsigned int input;
		printf("\nSeleccione alguna opcion...\n");
		printf("[0] - Finalizar\n");
		printf("[1] - Has value (Buscar un valor en el array)\n");
		printf("[2] - Get value (Insertar un elemento al final del array)\n");
		printf("[3] - Union arrays (Concatenar tres arrays en uno)\n");
		printf("\nDefina su opcion: ");
		scanf("%hu", &input);
		if(input >= 0 && input <= 3) {
			switch(input) {
				case 0: 
					return 0;
				break;
				case 1:
					
				break;
			}
		} else printf("\nOpcion invalida\n");
	}
}
