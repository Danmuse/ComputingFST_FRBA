#include "userConfig.h"

uint8_t ChooseMenuOption_1(void) {
	uint8_t option;
	bool checkValidEntry;
	printf("\nSeleccione alguna opcion...\n");
	printf("[0] - Finalizar\n");
	printf("[1] - Convertir de decimal a binario (Metodo de division)\n");
	printf("[2] - Convertir de decimal a binario (Metodo de resta)\n");
	printf("[3] - Convertir de decimal a una base [BINARIO - OCTAL - HEXADECIMAL]\n");
	while (!checkValidEntry) {
		printf("\nDefina su opcion: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			printf("Opcion invalida\n");
			while (getchar() != '\n');
		} else if (option > 3) {
			checkValidEntry = false;
			printf("Opcion invalida\n");
		}
	}
	return option;
}

uint8_t ChooseMenuOption_2(void) {
	uint8_t option;
	bool checkValidEntry;
	printf("\nSeleccione alguna opcion...\n");
	printf("[0] - Convertir de decimal a BINARIO\n");
	printf("[1] - Convertir de decimal a OCTAL\n");
	printf("[2] - Convertir de decimal a HEXADECIMAL\n");
	while (!checkValidEntry) {
		printf("\nDefina su opcion: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			printf("Opcion invalida\n");
			while (getchar() != '\n');
		} else if (option > 2) {
			checkValidEntry = false;
			printf("Opcion invalida\n");
		}
	}
	return option;
}

uint8_t CheckValidString(char* str) {
	while (*str != '\0') {
		if (!(*str >= '0' && *str <= '9')) return -1;
		str++;
	}
	return EXIT_SUCCESS;
}

char* Insert_String(char *buffer, size_t size) { 
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
	fgets(buffer, size, stdin);
	size = strlen(buffer);
	buffer[size - 1] = '\0';
	return buffer;
}