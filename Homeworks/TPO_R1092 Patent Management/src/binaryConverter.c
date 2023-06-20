#include "binaryConverter.h"

static char* DecimalToBinary(char*, char);

static void addByte(char*, char, bool);

static char* patToCode(char a, char b, char c, char d, char e, char f, char g);

static status_t codeToPat(char* n, char *a, char *b, char *c, char *d, char *e, char *f, char *g);

static char* DecimalToBinary(char* buffer, char inChar) {
	int8_t index;
    for (index = BYTE_LENGTH - 1; index >= 0; index--) {
        buffer[index] = (inChar & 1) ? '1' : '0';
        inChar >>= 1;
    }
    buffer[BYTE_LENGTH] = '\0';
	return buffer;
}

static void addByte(char* buffer, char inChar, bool byteBegin) {
	char charConverted[BYTE_LENGTH + 1];
	if (!byteBegin) {
		DecimalToBinary(charConverted, inChar);
		memmove(charConverted + 1, charConverted, BYTE_LENGTH + 1);
		*charConverted = ' ';
		strncat(buffer, charConverted, strlen(charConverted) + 1);
	} else {
		DecimalToBinary(charConverted, inChar);
		strncat(buffer, charConverted, strlen(charConverted) + 1);
	}
}

static char* patToCode(char a, char b, char c, char d, char e, char f, char g) {
	char* result = (char*) malloc(sizeof(char) * BIN_PATENT_LENGTH);
	addByte(result, a, true);
	addByte(result, b, false);
	addByte(result, c, false);
	addByte(result, d, false);
	addByte(result, e, false);
	addByte(result, f, false);
	if (g) addByte(result, g, false);
	return result;
}

static status_t codeToPat(char* n, char *a, char *b, char *c, char *d, char *e, char *f, char *g) {
	char* allocation = patToCode(*a, *b, *c, *d, *e, *f, *g);
	checkAllocate(allocation);
	strncpy(n, allocation, strlen(allocation) + 1);
	free(allocation);
	return ((*g && strlen(n) != BIN_PATENT_LENGTH - 1) || (!*g && strlen(n) != BIN_PATENT_LENGTH - BYTE_LENGTH - 2)) ? ERROR : SUCCESS;
}

void prtPatente(char a, char b, char c, char d, char e, char f, char g) {
	status_t result = SUCCESS;
	char patent[PATENT_LENGTH], patentConverted[BIN_PATENT_LENGTH];
	result = codeToPat(patentConverted, &a, &b, &c, &d, &e, &f, &g);
	sprintf(patent, "%c%c%c%c%c%c%c", a, b, c, d, e, f, g);
	fprintf(stdout, "INGRESO: %s\n", patent); // AA123ZZ
	fprintf(stdout, "CONVERSION: %s\n", patentConverted); // 01000001 01000001 00110001 00110010 00110011 01011010 01011010 
	if (result == SUCCESS) fprintf(stdout, "ESTADO: OK\n");
	else if (result == ERROR) fprintf(stdout, "ESTADO: ERROR\n");
}