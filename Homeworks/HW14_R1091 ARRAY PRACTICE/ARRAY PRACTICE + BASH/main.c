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
 
#include "functions.h"

int main(void) {
	int arr[SIZE], arr_2[SIZE], arr_3[SIZE];
	short int option, output_stdin = 0;
	init_arr(arr, SIZE);
	load_arr(arr, SIZE);
	size_arr(arr, SIZE);
	print_arr(arr);
	while(1) {
		show_menu();
		printf("\n\nDefina su opcion: ");
		output_stdin = scanf("%hd", &option);
		if(output_stdin != 1) option = 0; // Evita que sean ingresados los caracteres no numericos
		if(option >= 0 && option <= 3) {
			switch(option) {
				case 0: 
					return 0;
				break;
				case 1:
					first_case(arr);
				break;
				case 2:
					second_case(arr);
				break;
				case 3:
					third_case(arr, arr_2, arr_3);
				break;
			}
		} else printf("Opcion invalida");
	}
}
