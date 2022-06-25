#include <stdio.h>
#include <stdlib.h>

typedef __UINT8_TYPE__ uint8_t;

int main(void) {
	uint8_t i;
	// El caracter nulo al final del String es '\0'
	char arr_char[/*10*/] = {'H', 'o', 'l', 'a'};
	char str[] = {'H', 'o', 'l', 'a', '\0'};
	char str_entire[] = "Hola Mundo";
	printf("La cadena es \"%s\"\nNotese que al no haber definido un tamaño especifico, la cadena se repite\nTamaño en Bytes es %ld\n\n", arr_char, sizeof(arr_char));
	for(i = 0; i <= 8; i++) {
		printf("arr_char[%i] = %c %d%s\n", i, arr_char[i], arr_char[i], i == 8 ? "\n" : "");
	}
	printf("La cadena es \"%s\"\nTamaño en Bytes es %ld\n\n", str, sizeof(str));
	printf("La cadena es \"%s\"\nTamaño en Bytes es %ld\n", str_entire, sizeof(str_entire));
	return EXIT_SUCCESS;
}
