#include <stdio.h>

typedef struct {
	char x, y, z;
} data_t;

int main(void) {
	// Declarar e inicializar una estuctura...
	data_t *p, s = {'X', 'Y', 'Z'};
	p = &s;
	
	printf("p -> y: %c\n", p -> y);
	printf("(*p).y: %c\n", (*p).y); // Precedencia de operadores
	
	// Es necesario el parentesis porque el operador '.' tiene mayor precedencia que el operador '*'
	// printf("*p.y: %c\n", *p.y); // SINTAX ERROR
	return 0;
}
