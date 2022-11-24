#include "sys_num.h"

char* Insert_String(char *buffer, size_t size) { 
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
	fgets(buffer, size, stdin);
	size = strlen(buffer);
	buffer[size - 1] = '\0';
	return buffer;
}

//**************************************//
// Section Converter: BIN OCT HEX - DEC //
//**************************************//

char* strupper(char* str) {
	while (*str != '\0') {
		if (*str >= 'a' && *str <= 'z') *str -= 32;
		str++;
	}
	return str;
} 

int Binary_Decimal(char* input_string) {
	size_t i, lenght = strlen(input_string);
	int accumulator = 0, position = 0;
	for (i = 0; i < lenght; i++) {
		if (input_string[lenght - i - 1] != '1' && input_string[lenght - i - 1] != '0') return -1;
		accumulator += (input_string[lenght - i - 1] - '0') * pow(2, position);
		position++;
	}
	return accumulator;
}

int Octal_Decimal(char* input_string) {
	size_t i, lenght = strlen(input_string);
	int accumulator = 0, position = 0;
	for (i = 0; i < lenght; i++) {
		if (input_string[lenght - i - 1] >= '0' && input_string[lenght - i - 1] <= '7') {
			accumulator += (input_string[lenght - i - 1] - '0') * pow(8, position);
			position++;
		} else return -1;
	}
	return accumulator;
}

int Hexa_Decimal(char* input_string) {
	size_t i, lenght = strlen(input_string);
	int accumulator = 0, position = 0;
	strupper(input_string);
	for (i = 0; i < lenght; i++) {
		if (input_string[lenght - i - 1] >= '0' && input_string[lenght - i - 1] <= '9') {
			accumulator += (input_string[lenght - i - 1] - '0') * pow(16, position);
			position++;
		} else if (input_string[lenght - i - 1] >= 'A' && input_string[lenght - i - 1] <= 'F') {
			accumulator += (input_string[lenght - i - 1] - 'A' + 10) * pow(16, position);
			position++;
		} else return -1;
	}
	return accumulator;
}

//**************************************//
// Section Converter: DEC - BIN OCT HEX //
//**************************************//

uint8_t CheckValidString(char* str) {
	while (*str != '\0') {
		if (!(*str >= '0' && *str <= '9')) return -1;
		str++;
	}
	return EXIT_SUCCESS;
}

char* strreverse(char* str) {
	size_t lenght = strlen(str);
	uint8_t left, right;
	char aux;
	for (left = 0, right = lenght - 1; left < (lenght / 2); left++, right--) {
		aux = str[left];
		str[left] = str[right];
		str[right] = aux;
	}
	return str;
}

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
		default:
		break;
	}
}
