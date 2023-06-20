#include "binaryConverter.h"

char* DecimalSplit_Binary(char* output_string, char* input_string) {
	size_t index;
	uint16_t decimal = atoi(input_string);
	for (index = 0; decimal > 0; index++) {
		output_string[index] = (decimal % 2) + '0';
		decimal /= 2;
	}
	output_string[index] = '\0';
	if (strlen(output_string) == 0) strcpy(output_string, "0");
	return strreverse(output_string);
}

char* DecimalMinus_Binary(char* output_string, char* input_string) {
	size_t index;
	uint16_t decimal = atoi(input_string);
	bool checkFirstEntried;
	if (decimal == 0) strcpy(output_string, "0");
	for (index = 0; decimal > 0; index++) {
		if (decimal < pow(2, index) && decimal >= pow(2, index - 1)) {
			if (!checkFirstEntried)  {
				output_string[index - 1] = '1';
				output_string[index] = '\0';
				strreverse(output_string);
			} else output_string[strlen(output_string) - index] = '1';
			decimal -= pow(2, index - 1);
			checkFirstEntried = true;
			index = 0;
		} else output_string[index] = '0';
	}
	return output_string;
}

char* DecimalSplit_Octal(char* output_string, char* input_string) {
	size_t index;
	uint16_t decimal = atoi(input_string);
	for (index = 0; decimal > 0; index++) {
		output_string[index] = (decimal % 8) + '0';
		decimal /= 8;
	}
	output_string[index] = '\0';
	if (strlen(output_string) == 0) strcpy(output_string, "0");
	return strreverse(output_string);
}

char* DecimalSplit_Hexa(char* output_string, char* input_string) {
	size_t index;
	uint16_t decimal = atoi(input_string);
	for (index = 0; decimal > 0; index++) {
		if (decimal % 16 < 10) output_string[index] = (decimal % 16) + '0';
		else output_string[index] = (decimal % 16) - 10 + 'A';
		decimal /= 16;
	}
	output_string[index] = '\0';
	if (strlen(output_string) == 0) strcpy(output_string, "0");
	return strreverse(output_string);
}

char* DecimalSplit_SomeBase(char* output_string, char* input_string, BASE_t base) {
	switch(base) {
		case BIN:
			return DecimalSplit_Binary(output_string, input_string);
		break;
		case OCT:
			return DecimalSplit_Octal(output_string, input_string);
		break;
		case HEX:
			return DecimalSplit_Hexa(output_string, input_string);
		break;
	}
}