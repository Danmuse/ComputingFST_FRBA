#include "functions.h"

void show_menu(void) {
	printf("\n\nSeleccione alguna opcion...\n");
	printf("[0] - Finalizar\n");
	printf("[1] - Has value (Buscar un valor en el array)\n");
	printf("[2] - Get value (Insertar un elemento al final del array)\n");
	printf("[3] - Union arrays (Concatenar dos arrays en uno)");
}

void first_case(int arr[]) {
	int input_value;
	short int out_function;
	printf("\nRecibido, ingrese un valor: ");
	scanf("%d", &input_value);
	out_function = has_value(input_value, arr);
	if (out_function >= 0) printf("El elemento con dicho valor se encuentra en arr[%hd]\n", out_function);
	else printf("No se encuentra un elemento con dicho valor\n");
}

void second_case(int arr[]) {
	int input_value;
	short int out_function;
	printf("\nRecibido, ingrese un valor: ");
	scanf("%d", &input_value);
	out_function = get_value(input_value, arr, SIZE);
	if (out_function == 0) print_arr(arr);
	else printf("Lo sentimos, el array esta completo\n");
}

void third_case(int arr[], int arr_2[], int arr_3[]) {
	short int out_function;
	printf("\nRecibido, inserte valores en el segundo array...");
	init_arr(arr_2, SIZE);
	load_arr(arr_2, SIZE);
	printf("\nInserte valores en el tercer array...");
	init_arr(arr_3, SIZE);
	load_arr(arr_3, SIZE);
	out_function = union_arrs(arr, arr_2, arr_3, SIZE);
	if (out_function == 0) print_arr(arr);
	else printf("\nLo sentimos, el array esta completo");
}

void init_arr(int a[], int max_size) {
	size_t i;
	for (i = 0; i < max_size; i++) a[i] = 0;
}

void load_arr(int a[], int max_size) {
	size_t i;
	printf("\nIngrese por el teclado los valores para cada elemento. Envie \"0\" para salir\n");
	while (1) {
		for (i = 0; i < max_size; i++) {
			printf("arr[%li] = ", i);
			scanf("%d", &a[i]); // Equal to "scanf("%d", a + i);"
			if (a[i] == 0) break;
			else if (a[i] > 1000 || a[i] < -1000) break;
		} if (*a != 0) break; // Se rompe al colocar una letra
	} 
}

void size_arr(int a[], int max_size) {
	size_t i;
	for (i = 0; i < max_size; i++) if(a[i] == 0) break;
	printf("\nEl tamanio del array es: %ld Elemento%c\n", i, i == 1 ? 0 : 115);
}

short int has_value(int a, int b[]) {
	size_t i;
	short int pos = -1;
	for (i = 0; *(b + i) != 0; i++) 
		if (b[i] == a) pos = i;
	return pos;
}

short int get_value(int a, int b[], int max_size) {
	size_t i;
	short int prompt = 0;
	for (i = 0; i < max_size; i++) {
		if (b[i] == 0) {
			b[i] = a;
			break;
		} else if (i == max_size - 1 && b[i] != 0) prompt = 1;
	}
	return prompt;
}

short int union_arrs(int a[], int b[], int c[], int max_size) {
	size_t i, arr_len = 0, arr2_len = 0;
	short int prompt = 0;
	for (i = 0; *(a + i) != 0; i++) arr_len++;
	for (i = 0; *(b + i) != 0; i++) arr2_len++;
	if (arr_len < max_size) {
		for (i = 0; arr_len + i < max_size; i++) {
			if (*(b + i) != 0) a[arr_len + i] = b[i];
			else a[arr_len + i] = c[i - arr2_len];
		}
	} else prompt = 1;
	return prompt;
}

void print_arr(int a[]) {
	size_t count = 0;
	printf("\nLos elementos del array son: \n");
	while (*a != 0 && *a <= 1000 && *a >= -1000) {
		printf("%d%s", *a, count % 5 < 4 ? "\t" : "\n");
		count++;
		a++;
	}
}
