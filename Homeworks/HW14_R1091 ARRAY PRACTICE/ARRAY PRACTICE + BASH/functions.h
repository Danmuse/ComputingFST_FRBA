#include <stdio.h>
#define SIZE 10

void show_menu(void);
void first_case(int a[]);
void second_case(int a[]);
void third_case(int a[], int a2[], int a3[]);
void init_arr(int a[], int max_size);
void load_arr(int a[], int max_size);
void size_arr(int a[], int max_size);
short int has_value(int a, int b[]);
short int get_value(int a, int b[], int max_size);
void print_arr(int a[]);
short int union_arrs(int a[], int b[], int c[], int max_size);
