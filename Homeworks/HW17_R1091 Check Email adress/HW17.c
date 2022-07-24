/****************************************************************************************
 * Realizar una funciona para validar que una cadena es un email int es_email(char *s); *
 * Devuelve (int) 1 si el string especificado es un email.                              *
 * Debe cumplir que contenga el caracter '@' y al menos un carater '.' luego.           *
 ****************************************************************************************/

#include <stdio.h>
int is_email(char *);

int main(int argc, char *argv[]) {
	int out_function = 0;
	if(argc == 2) {
		out_function = is_email(argv[argc - 1]);
		out_function ? printf("El texto ingresado es una direccion de correo electronico\n") :
		printf("El texto ingresado no posee un formato de correo electronico\n");
	} else printf("En la ejecucion del programa debe ingresar una direccion de correo eletronico sin espacios\n"); 
	return 0;
}

int is_email(char *src) {
	int prompt = 0, st_content = 0;
	while(*src != '\0') {
		if((st_content == 0 && *src >= 'a' && *src <= 'z') || (st_content == 0 && *src > 'A' && *src < 'Z')) st_content++;
		else if(st_content == 1 && *src == '@') st_content++;
		else if((st_content == 2 && *src >= 'a' && *src <= 'z') || (st_content == 0 && *src > 'A' && *src < 'Z')) st_content++;
		else if(st_content == 3 && *src == '.') st_content++;
		else if((st_content == 4 && *src >= 'a' && *src <= 'z') || (st_content == 0 && *src > 'A' && *src < 'Z')) prompt = 1;
		else if((*src > ' ' && *src < '0') || (*src > '9' && *src < 'A') || (*src > 'Z' && *src < 'a') || (*src > 'z' && *src < 254)) {
			prompt = 0;
			break;
		}
		src++;
	}
	return prompt;
}
