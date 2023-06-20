#include "binaryConverter.h"
#include "userConfig.h" 

#define MAX_SIZE 9

int main(void) {
	char decimal_string[MAX_SIZE];
	while(1) {
		switch(ChooseMenuOption()) {
			case 0:
				return EXIT_SUCCESS;
			break;
			case 1:
				fprintf(stdout, "Ingrese el modelo de patente: ");
				if (Insert_String(decimal_string, MAX_SIZE)) break;
				prtPatente(decimal_string[0], decimal_string[1], decimal_string[2], decimal_string[3], decimal_string[4], decimal_string[5], decimal_string[6]);
			break;
			default:
			break;
		}
	}
}