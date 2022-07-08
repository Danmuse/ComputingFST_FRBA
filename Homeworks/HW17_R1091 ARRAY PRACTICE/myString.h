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
 
void init_arr(int a[], int max_size);
void load_arr(int a[], int max_size);
void size_arr(int a[], int max_size);
int has_value(int a, int b[]);
int get_value(int a, int b[], int max_size);
void print_arr(int a[]);
int union_arrs(int a[], int b[], int c[], int max_size);
