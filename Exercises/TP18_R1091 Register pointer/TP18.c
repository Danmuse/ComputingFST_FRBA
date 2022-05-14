#include <stdio.h>

int main (void){
        int *px, x = 10;
	printf("\nTamaño de cualquier puntero es %ld\nTamaño de varible entera es %ld\n\n", sizeof(px), sizeof(x));
	px = &x;
	printf("El puntero vale %p (px) que es lo mismo que la direccion de la varible porque fue igualada\n\n", px);
	printf("La direccion del puntero es %p (&px)\n", &px);
	printf("La direccion de la variable es %p (&x)\n", &x);
	printf("El contenido de la variable es %d (*px)\n\n", *px); // En este caso "*" se le llama variable de interacción.
	return 0;
}
