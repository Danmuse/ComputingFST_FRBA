/************************************************************************************************************************
 * Escribir un programa que encripte un archivo realizando el NOT a nivel de bits de cada uno de sus bytes.             *
 * El programa recibira por linea de comandos el nombre del archivo a encriptar y creara un archivo con el mismo nombre *
 * anteponiendo la palabra "crypto_" a su nombre original.                                                              *
 ************************************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>

unsigned char* NoExclusive_Convert(unsigned char* bits, int size); // NOT Bit Operation

typedef __UINT8_TYPE__ uint8_t;

int main(int argc, char* argv[]) {
    size_t index = 0;
    int FileDescriptor;
    unsigned char* Buffer, BufferEncrypt;
    int response;
    
    /*
    
    if (argc == 2) {
        FileDescriptor = open(argv[1], O_RDONLY);
        response = lseek(FileDescriptor, 0, SEEK_END);
    	lseek(FileDescriptor, 0, SEEK_SET);
  	Buffer = (unsigned char*) malloc(response);
        while (a) {
            response = read(FileDescriptor, Buffer + index, 1);
            *(Buffer + index) = ~*(Buffer + index);
            index++;
        }
        close(FileDescriptor);
        BufferEncrypt = (unsigned char *) malloc(strlen(argv[1]) + 8);
        strcpy(BufferEncrypt, "crypto_");
        strcat(BufferEncrypt, argv[1]);
        FileDescriptor = open(BufferEncrypt, O_RDWR | O_CREAT, 0666);

        write(FileDescriptor, Buffer, index - 1);
        close(FileDescriptor);
    } else printf("En la ejecucion del programa debe ingresar nombre del archivo que desee encriptar\n");
    
    */
    
    FileDescriptor = open(argv[1], O_RDONLY);
    response = lseek(FileDescriptor, 0, SEEK_END); // Devuelve la cantidad de bytes que existen antes de su posicion
    lseek(FileDescriptor, 0, SEEK_SET);
    Buffer = (unsigned char*) malloc(response);
    response = read(FileDescriptor, Buffer, response); // Devuelve la cantidad de bytes leidos, almacena los bytes en Buffer
    close(FileDescriptor);
    FileDescriptor = open("./crypto", O_RDWR | O_CREAT, 0666);
    write(FileDescriptor, NoExclusive_Convert(Buffer, response), response);
    close(FileDescriptor);

    return 0;
}

unsigned char* NoExclusive_Convert(unsigned char* bits, int size) {
	size_t i;
	for (i = 0; i < size; i++) bits[i] = ~bits[i];
	return bits;
}
