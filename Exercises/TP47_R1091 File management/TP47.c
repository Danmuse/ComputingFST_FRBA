// https://docs.kernel.org/filesystems/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int response, data = 1;
	
	// 1er paso: Abrir el archivo
	FILE* fp; // Solicita memoria!! Debe ser liberada con "fclose(FILE*)" 
	// fp = fopen([PATH_NAME], [MODE] - "w" (write), "r" (read), "a" (append));
	fp = fopen("intro.dat", "w");
	// "write" sobreescribe el archivo
	// "append" agrega al archivo
	
	// 2do paso: Verificar fopen
	if (fp == NULL) {
		printf("No se puede abrir el archivo");
		exit(-1);
	}	
	
	// 3 paso: Leer/Escribir
	// "response" es lo devuelto por "fwrite(...)" segun la cantidad de bloques que pudo grabar
	response = fwrite(&data, sizeof(data), 1, fp);
	printf("Se escribieron %d bloque de %ld byte/s\n", response, sizeof(data));
	
	// 4 paso: Cerrar el archivo
	fclose(fp); // Equivalente a un "free()"
	return 0;
}
