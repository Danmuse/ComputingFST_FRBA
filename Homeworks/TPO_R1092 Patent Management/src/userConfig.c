#include "userConfig.h"

static status_t CheckValidString(const char*);

static status_t CheckPatent(char*, size_t);

static status_t CheckValidString(const char* str) {
	while (*str != '\0') {
		if (!((*str >= '0' && *str <= '9') || (*str >= 'A' && *str <= 'Z'))) return FAILURE;
		str++;
	}
	return SUCCESS;
}

static status_t CheckPatent(char* buffer, size_t size) {
	status_t result = SUCCESS;
	if (strlen(buffer) - 1 < size - OLD_PATENT_INDEX || (strlen(buffer) == size - 1 && buffer[size - 2] != '\n')) result = FAILURE;
	buffer[strlen(buffer) - 1] = '\0';
	if (CheckValidString(buffer)) result = FAILURE;
	else if (strlen(buffer) == size - NEW_PATENT_INDEX && 
			!(buffer[0] == 'A' &&
			(buffer[1] >= 'A' && buffer[1] <= 'G') &&
			(buffer[2] >= '0' && buffer[2] <= '9') &&
			(buffer[3] >= '0' && buffer[3] <= '9') &&
			(buffer[4] >= '0' && buffer[4] <= '9') &&
			(buffer[5] >= 'A' && buffer[5] <= 'Z') &&
			(buffer[6] >= 'A' && buffer[6] <= 'Z'))) result = FAILURE;
	else if (strlen(buffer) == size - OLD_PATENT_INDEX && 
			!((buffer[0] >= 'A' && buffer[0] <= 'P') &&
			(buffer[1] >= 'A' && buffer[1] <= 'X') &&
			(buffer[2] >= 'A' && buffer[2] <= 'Z') &&
			(buffer[3] >= '0' && buffer[3] <= '9') &&
			(buffer[4] >= '0' && buffer[4] <= '9') &&
			(buffer[5] >= '0' && buffer[5] <= '9'))) result = FAILURE;
	if (result == FAILURE) fprintf(stdout, "ERROR: Patente invalida\n");
	return result;
}

uint8_t ChooseMenuOption(void) {
	uint8_t option;
	bool checkValidEntry;
	fprintf(stdout, "\nSeleccione alguna opcion...\n");
	fprintf(stdout, "[0] - Finalizar\n");
	fprintf(stdout, "[1] - Convertir patente\n");
	while (!checkValidEntry) {
		printf("\nDefina su opcion: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			fprintf(stdout, "ERROR: Opcion invalida\n");
			while (getchar() != '\n');
		} else if (option > 1) {
			checkValidEntry = false;
			fprintf(stdout, "ERROR: Opcion invalida\n");
		}
	}
	return option;
}

status_t Insert_String(char *buffer, size_t size) { 
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
	fgets(buffer, size, stdin);
	if (CheckPatent(buffer, size)) return FAILURE; 
	return SUCCESS;
}