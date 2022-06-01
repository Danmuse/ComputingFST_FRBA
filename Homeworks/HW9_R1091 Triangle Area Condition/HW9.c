/**************************************************************************
 * Recibir ternas de valores que correspondan a un triangulo		  *
 * Si es asi calcular el area						  *
 * Si no corresponde a un triangulo, entonces sale de la funcion ciclica  *
 * Al finalizar muestro el triangulo con mayor area			  *
 **************************************************************************/

#include <stdio.h>
#include <math.h>
#define TRUE 1

int calc_area(float, float, float, float *);

int main(void) {
	int INPUT, output, i, pos = 0;
	float r_area = 0, max_area = 0, side_1, side_2, side_3;
	float *sides[] = { &side_1, &side_2, &side_3 };
	printf("\nIngrese 3 valores que correspondan a los lados de un triangulo...\n");
	while (TRUE) {
		for (i = 0; i < 3; i++) {
			printf("Valor #%i: ", i);
			output = scanf("%f", sides[pos]);
			pos++;
		}
		
		if (output == 0) {
			printf("\nAlguno de los valores ingresados no son correctos\n");
			break;
		}	else calc_area (side_1, side_2, side_3, &r_area);
		
		INPUT = calc_area(side_1, side_2, side_3, &r_area);
		
		if (r_area > max_area) max_area = r_area; 
		if (INPUT == 1) break;
		printf("Area: %.2f\n\n", r_area);
		pos = 0;
	}
	
	printf("\nLos datos ingresados no validan que sea un triangulo\n");
	printf("\nEl area maxima de las ternas ingresadas fue %.2f\n", max_area);
	return 0;
}

int calc_area(float a, float b, float c, float *area) {
	int debug = 0;
	float mp_a, mp_b, mp_c, radicando;
	mp_a = ((a + b + c) / 2) - a;
	mp_b = ((a + b + c) / 2) - b;
	mp_c = ((a + b + c) / 2) - c;
	radicando = (((a + b + c) / 2) * mp_a * mp_b * mp_c);

	*area = sqrt(radicando);

	if (radicando <= 0) debug = 1;	// Area = Unidad Imaginaria o Inexistente
	return debug;
}
