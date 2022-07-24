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
#define SIZE 10

int main(void) {
	int arr[SIZE], arr_2[SIZE], arr_3[SIZE], input_value;
	short int option, output_stdin = 0, out_function;
	init_arr(arr, SIZE);
	load_arr(arr, SIZE);
	size_arr(arr, SIZE);
	print_arr(arr);
	printf("\n\nSeleccione alguna opcion...\n");
	printf("[0] - Finalizar\n");
	printf("[1] - Has value (Buscar un valor en el array)\n");
	printf("[2] - Get value (Insertar un elemento al final del array)\n");
	printf("[3] - Union arrays (Concatenar dos arrays en uno)");
	while(1) {
		printf("\n\nDefina su opcion: ");
		output_stdin = scanf("%hd", &option);
		if(output_stdin != 1) option = 0; // Evita que sean ingresados los caracteres no numericos
		if(option >= 0 && option <= 3) {
			switch(option) {
				case 0: 
					return 0;
				break;
				case 1:
					printf("\nRecibido, ingrese un valor: ");
					scanf("%d", &input_value);
					out_function = has_value(input_value, arr);
					if(out_function >= 0) printf("El elemento con dicho valor se encuentra en arr[%hd]\n", out_function);
					else printf("No se encuentra un elemento con dicho valor\n");
				break;
				case 2: 
					printf("\nRecibido, ingrese un valor: ");
					scanf("%d", &input_value);
					out_function = get_value(input_value, arr, SIZE);
					if(out_function == 0) print_arr(arr);
					else printf("Lo sentimos, el array esta completo\n");
				break;
				case 3: 
					printf("\nRecibido, inserte valores en el segundo array...");
					init_arr(arr_2, SIZE);
					load_arr(arr_2, SIZE);
					printf("\nInserte valores en el tercer array...");
					init_arr(arr_3, SIZE);
					load_arr(arr_3, SIZE);
					out_function = union_arrs(arr, arr_2, arr_3, SIZE);
					if(out_function == 0) print_arr(arr);
					else printf("\nLo sentimos, el array esta completo");
				break;
			}
		} else printf("Opcion invalida");
	}
}
