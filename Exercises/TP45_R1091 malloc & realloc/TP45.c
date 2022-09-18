#include <stdio.h>
#include <stdlib.h>

typedef __UINT8_TYPE__ uint8_t;

typedef enum {
	FALSE = 0,
	TRUE = 1
} my_boolean;

uint8_t realloc_ctrl(char *, uint8_t);
void show_reserved_memory(char *, uint8_t);

int main(void) {
	my_boolean exit_flag = FALSE;
	uint8_t index, MAX_CHARS, CURRENT_MAX_CHARS;
	char *memory_container;
	
	printf("\nIngrese la cantidad de caracteres: ");
	scanf("%hhu", &MAX_CHARS);
	memory_container = (char *) malloc(MAX_CHARS * sizeof(char));
	if (!memory_container) exit(0);
	
	printf("La posicion y el contenido de la memoria reservada es: \n");
	show_reserved_memory(memory_container, MAX_CHARS);
	
	for (index = 0; index < MAX_CHARS; index++) {
		printf("%cIngrese el caracter #%hhu: ", index == 0 ? '\n' : '\0', index);
		scanf("%s", &memory_container[index]);
		
		/************************************* Character BUG/DEBUG *************************************
		scanf("%c", &memory_container[i]);
		while (memory_container[i] < 32) {
			printf("\nEntry alert! Invalid character\n"); // '\n' is the invalid character
			printf("Reingrese el caracter #%ld: ", memory_container[i], memory_container[i], i);
			scanf("%c", &memory_container[i]);
		}
		************************************************************************************************/
	}
	
	printf("\n--- Se han ingresado correctamente los caracteres ---\n");
	show_reserved_memory(memory_container, MAX_CHARS);
	
	while (!exit_flag) {
		CURRENT_MAX_CHARS = realloc_ctrl(memory_container, MAX_CHARS);
		if (CURRENT_MAX_CHARS > MAX_CHARS) {
			for (index = MAX_CHARS; index < CURRENT_MAX_CHARS; index++) {
				printf("%cIngrese el caracter #%hhu: ", index == 0 ? '\n' : '\0', index);
				scanf("%s", &memory_container[index]);
			}
			MAX_CHARS = CURRENT_MAX_CHARS;
			printf("\n--- Se han ingresado correctamente los caracteres ---\n");
			show_reserved_memory(memory_container, MAX_CHARS);
		} else if (CURRENT_MAX_CHARS == MAX_CHARS) exit_flag = TRUE;
		else {
			MAX_CHARS = CURRENT_MAX_CHARS;
			printf("\n--- Se han redistrubuido correctamente los caracteres en la memoria ---\n");
			show_reserved_memory(memory_container, MAX_CHARS);
		}
	}
	
	free(memory_container);
	return EXIT_SUCCESS;
}

uint8_t realloc_ctrl(char *memory_container, uint8_t CURRENT_MAX_CHARS) {
	uint8_t confirm;
	printf("\nDesea redefinir la cantidad de caracteres?\nIngrese '0' para NO y '1' para SI... ");
	scanf("%hhu", &confirm);
	if (confirm) {
		printf("Ingrese la cantidad de caracteres: ");
		scanf("%hhu", &CURRENT_MAX_CHARS);
		memory_container = (char *) realloc(memory_container, CURRENT_MAX_CHARS * sizeof(char));
		if (!memory_container) exit(0);
		printf("La posicion y el contenido de la memoria reservada es: \n");
		show_reserved_memory(memory_container, CURRENT_MAX_CHARS);
	}
	return CURRENT_MAX_CHARS;
}

void show_reserved_memory(char *memory_container, uint8_t SIZE) {
	size_t i;
	for (i = 0; i < SIZE; i++) printf("#%ld - %p\t%c\n", i, &memory_container[i], memory_container[i]);
} 
