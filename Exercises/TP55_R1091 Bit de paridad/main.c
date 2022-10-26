/******************************************************
 * Calcular el BIT de paridad de un conjunto de bits. *
 ******************************************************/

// El bit de paridad, a diferencia de los bits de inicio y de parada, es un parámetro opcional que se utiliza 
// En las comunicaciones serie para determinar si el dispositivo remoto está recibiendo correctamente 
// El carácter de datos que se transmite.

#include <stdio.h>
#define SIZE 3

typedef __UINT8_TYPE__ uint8_t;

unsigned char Paridad(unsigned char* bits, int size);

int main(void) {
	unsigned char First_Data[SIZE] = {0x90, 0xF0, 0x87};
	printf("0x%X\n", Paridad(First_Data, SIZE));
	return 0;
}

unsigned char Paridad(unsigned char* bits, int size) {
	unsigned char result = 0;
	uint8_t amount;
	size_t i, j;
	for (i = 0; i < 8; i++) {
		amount = 0;
		for (j = 0; j < size; j++)
			// unsigned char mask = 1 << i;
			// if (bits[i] & mask) amount++;
			if (bits[j] & (1 << i)) amount++;
		if (amount % 2) result = result | (1 << i);
	}
	return result;
}
