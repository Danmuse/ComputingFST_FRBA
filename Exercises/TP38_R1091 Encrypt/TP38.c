/**********************************
 * Pacial de 2020 - Informatica 1 *
 **********************************/

#include "encrypt.h"

int main(void) {
	int input_rand;
	char src[20] = "HOLA 8504", dest[22];
	srand(getpid());
	// input_rand = scroll_letters(src, dest);
	encrypt_numbers(src, dest);
	// input_rand != -1 ? printf("%s\t\t%s\n", src, dest) : printf("No es posible encriptarlo\n");
	printf("%s\t\t%s\n", src, dest);
	
	// for(input_rand = 0; input_rand <= 254; input_rand++) printf("%c\t%d\n", input_rand, input_rand);
	/* 65 - 90 / A - Z */
	/* 48 - 57 / 0 - 9 */
	return 0;
}
