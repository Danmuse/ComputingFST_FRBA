/**************************************************************************
 * Recibir ternas de valores que correspondan a un triangulo		  *
 * Si es asi calcular el area						  *
 * Si no corresponde a un triangulo, entonces sale de la funcion ciclica  *
 * Al finalizar muestro el triangulo con mayor area			  *
 **************************************************************************/

#include <stdio.h>
#include <math.h>
#define TRUE 1

int area(int, int, int, float *);

int main(void) {
	int INPUT, output, side_1, side_2, side_3;
	float r_area = 0, max_area = 0;
	printf("\nIngrese 3 valores que correspondan a los lados de un triangulo...\n");
	while(TRUE) {
		printf("Valor #1: ");
		output = scanf("%d", &side_1);
		printf("Valor #2: ");
		output = scanf("%d", &side_2);
		printf("Valor #3: ");
		output = scanf("%d", &side_3);
		output == 0 ? printf("\n\nAlguno de los valores ingresados no son correctos\n") :
		area(side_1, side_2, side_3, &r_area);
		INPUT = area(side_1, side_2, side_3, &r_area);
		if(INPUT == 0) {
			if (r_area > max_area) max_area = r_area;
		} else break;
		printf("Area: %.2f\n", r_area);
	}
	printf("Los datos ingresados no validan que sea un triangulo\n\n");
	printf("El area maxima de las ternas ingresadas fue %.2f\n", max_area);
	return 0;
}

int area(int a, int b, int c, float *area) {
	int mp_a, mp_b, mp_c, debug = 0;
	mp_a = ((a + b + c) / 2) - a;
	mp_b = ((a + b + c) / 2) - b;
	mp_c = ((a + b + c) / 2) - c;
	if (a + b > c) *area = sqrt(((a + b + c) / 2) * mp_a * mp_b * mp_c);
	if (a + c > b) *area = sqrt(((a + b + c) / 2) * mp_a * mp_b * mp_c);
	if (b + c > a) *area = sqrt(((a + b + c) / 2) * mp_a * mp_b * mp_c);
	else debug = 1;
	return debug;
}
