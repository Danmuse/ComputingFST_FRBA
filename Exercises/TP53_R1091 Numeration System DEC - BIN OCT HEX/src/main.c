#include "binaryConverter.h"
#include "userConfig.h"

#define MAX_SIZE 30

int main(void) {
	char decimal_string[MAX_SIZE], result_string[MAX_SIZE];
	while(1) {
		switch(ChooseMenuOption_1()) {
			case 0:
				return EXIT_SUCCESS;
			break;
			case 1:
				printf("Ingrese el valor decimal que desea convertir: ");
				Insert_String(decimal_string, MAX_SIZE);
				!CheckValidString(decimal_string) ? 
				printf("El resultado en binario es: %s\n", DecimalSplit_Binary(result_string, decimal_string)) :
				printf("El valor ingresado no se corresponde a la base\n");
			break;
			case 2:
				printf("Ingrese el valor decimal que desea convertir: ");
				Insert_String(decimal_string, MAX_SIZE);
				!CheckValidString(decimal_string) ? 
				printf("El resultado en binario es: %s\n", DecimalMinus_Binary(result_string, decimal_string)) :
				printf("El valor ingresado no se corresponde a la base\n");
			break;
			case 3:
				printf("Ingrese el valor decimal que desea convertir: ");
				Insert_String(decimal_string, MAX_SIZE);
				if (!CheckValidString(decimal_string)) {
					BASE_t base = (BASE_t)ChooseMenuOption_2();
					DecimalSplit_SomeBase(result_string, decimal_string, base);
					if (base == BIN) printf("El resultado en binario es: %s\n", result_string);
					else if (base == OCT) printf("El resultado en octal es: %s\n", result_string);
					else if (base == HEX) printf("El resultado en haxadecimal es: %s\n", result_string);
				} else printf("El valor ingresado no se corresponde a la base\n");
			break;
			default:
			break;
		}
	}
}