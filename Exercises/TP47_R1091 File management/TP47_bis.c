// https://docs.kernel.org/filesystems/

#include <stdio.h> 
#include <stdlib.h>

int main(void) {
	int data_01 = 1; 
	int data_02 = 2; 
	
	FILE *fp;
	fp = fopen("database.dat", "a");
	if (fp == NULL) { 
		printf("No se puedo abrir el archivos"); 
		exit(-1); 
	}
	fwrite(&data_01, sizeof(data_01), 1, fp); 
	fwrite(&data_02, sizeof(data_02), 1, fp); 
	fclose(fp); 
	return 0;
} 
