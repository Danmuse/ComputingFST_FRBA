/****************************************************************************************************
 * Realizar un programa para la gestión de stock de materiales, en donde se debe ingresar el nombre *
 * del material y su stock. Para un material se pueden ir ingresando altas y bajas del mismo.       *
 * Se desconoce la cantidad de materiales, pero se sabe que no superará los 100 materiales.         *
 * El ingreso de datos finaliza con stock cero (0). Una vez finalizado el ingreso, se debe informar *
 * ~ Stock promedio ~ Listar los materiales con stock inferiores al promedio ~                      *
 ****************************************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 100
#define SIZE 20

typedef enum {
	CONTINUE = 0,
	EXIT = 1
} Exit_t;

typedef struct {
	char name[SIZE];
	int stock;
} Material_t;

void str_upperCase(char *);
float averageStock(Material_t []);

int main(void) {
	size_t i, j;
	int accumulator = 0;
	float average;
	Exit_t exit;
	Material_t inventory[MAX_ITEMS];
	for (i = 0; i < MAX_ITEMS; i++) {
		if (exit) break;
		printf("\nIngrese el nombre del material [%ld]: ", i);
		scanf("%s", inventory[i].name);
		str_upperCase(inventory[i].name);
		// NOTE: 'A' = 65 (ASCCI)
		if (*inventory[i].name < 65) break; // Avoid continuing if the first character isn't a letter or symbol
		for (j = 0; j <= i; j++) {
			// printf("%s[%ld] - %s[%ld]\n", inventory[i].name, i, inventory[j].name, j);
			// Enters if the material currently entered is equal to one of the above
			if (!strcmp(inventory[i].name, inventory[j].name) && i != j) {
				printf("Modifique el stock del material [%ld]: ", j);
				scanf("%d", &inventory[j].stock);
				*inventory[i].name = '\0';
				i--;
				// Avoid continuing if the stock entered isn't a number or equal to zero
				if (!inventory[j].stock) exit = EXIT;
				break;
			} else {
				printf("Ingrese el stock del material [%ld]: ", i);
				scanf("%d", &inventory[i].stock);
				// Avoid continuing if the stock entered isn't a number or equal to zero
				if (!inventory[i].stock) {
					*inventory[i].name = '\0';
					exit = EXIT;
				}
				break;
			}
		}
	}
	
	for (i = 0; *inventory[i].name > 64 && i < MAX_ITEMS; i++) accumulator += inventory[i].stock;
	printf("Total acumulado: %d items\n", accumulator);
	// average = (float)(accumulator / (int) i);
	// printf("Stock promedio: %.0f items\n", average);
	
	average = averageStock(inventory); // Comment it to present...
	// printf("Stock promedio: %.0f items\n", average);
	// for (i = 0; *inventory[i].name > 64 && i < MAX_ITEMS; i++) if (inventory[i].stock < average) printf("\n%s - %d\n", inventory[i].name, inventory[i].stock); // PARA LISTAR INFERIORES AL STOCK
	return 0;
}

void str_upperCase(char *str) {
	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z') *str -= 'a' - 'A';
		str++;
	}
}

float averageStock(Material_t aux[]) {
	size_t i;
	int accumulator = 0;
	float output;
	for (i = 0; *aux[i].name > 64 && i < MAX_ITEMS; i++) accumulator += aux[i].stock;
	output = (float)(accumulator / (int) i);
	return output;
}
