// Recibir 3 valores que correspondan a los lados de un triangulo.
// Calcule el area.
// Calcule el perimetro.
// Determine que tipo de triangulo es.

#include <stdio.h>
#include <math.h>
// #include <iostream>	 // <file.c> -std=c99

// using namespace std;	 // <file.c> -std=c99

int calc_Triangle(int, int, int, int *, int *, int *);

int main(void) {
	int INPUT, output, side_1, side_2, side_3;
	int area = 0, perimetro = 0, type = 0;
	char *s_type[] = { "Equilatero", "Isosceles", "Escaleno" };
	printf("\nIngrese 3 valores que correspondan a cada lado de un triangulo:\n");

	// cout << "Valor #1: "; cin >> &side_1;	 // <file.c> -std=c99
	// cout << "Valor #2: "; cin >> &side_2;	 // <file.c> -std=c99
	// cout << "Valor #3: "; cin >> &side_3;	 // <file.c> -std=c99

	printf("Valor #1: ");
	output = scanf("%d", &side_1);
	printf("Valor #2: ");
	output = scanf("%d", &side_2);
	printf("Valor #3: ");
	output = scanf("%d", &side_3);

	if (output != 1) printf("\nLos valores ingresados son incorrectos\n");
	else {
		calc_Triangle(side_1, side_2, side_3, &area, &perimetro, &type);
		INPUT = calc_Triangle(side_1, side_2, side_3, &area, &perimetro, &type);

		switch (INPUT){
			case 0: printf("\nArea: %d\nPerimetro: %d\nTipo: %s\n", area, perimetro, s_type[type]); break;
			case 1: printf("\nArea: Unidad Imaginaria (NAN)\n"); break;
			case 2: printf("\nArea: Area Inexistente\nPerimetro: %d\nTipo: %s\n", perimetro, s_type[type]); break;
		}
	}

	return 0;
}

int calc_Triangle(int a, int b, int c, int *area, int *perimetro, int *type) {
	int mp_a, mp_b, mp_c, debug = 0;
	mp_a = ((a + b + c) / 2) - a;
	mp_b = ((a + b + c) / 2) - b;
	mp_c = ((a + b + c) / 2) - c;

	*area = sqrt(((a + b + c) / 2) * mp_a * mp_b * mp_c);
	*perimetro = a + b + c;

	if (mp_a < 0 || mp_b < 0 || mp_c < 0) debug = 1;		// Area = Unidad Imaginaria
	if (*area == 0) debug = 2;					// Area = Area Inexistente
	if (a == b && a == c) *type = 0;				// Tipo = Equilatero
	if ((a == b && a != c) || (a != b && a == c)) *type = 1;	// Tipo = Isosceles
	if (a != b && a != c) *type = 2;				// Tipo = Escaleno

	// a + b > c
	// a + c > b
	// b + c > a
	// Si cualquiera de esas 3 condiciones no se cumple, entonces Area = Area Inexistente.

	return debug;
}
