#include <stdio.h>

void print_str(char *);

int main(void) {
	char str[50] = "Esta es una funcion comprendida por strings";
	print_str(str);
	printf("%s\n", &str[5]); // Me desplazo en el string e imprimo a partir del indice dado
	return 0;
}

void print_str(char *text) { puts(text); }
