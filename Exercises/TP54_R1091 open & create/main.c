#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <malloc.h>

int main(void) {
    int FileDescriptor;
    char* Buffer;
    int response;
    FileDescriptor = open("./original", O_RDONLY);
    response = lseek(FileDescriptor, 0, SEEK_END);
    lseek(FileDescriptor, 0, SEEK_SET);
    Buffer = (char *) malloc(response);
    response = read(FileDescriptor, Buffer, response);
    close(FileDescriptor);
    FileDescriptor = open("./copia", O_RDWR | O_CREAT, 0666);
    write(FileDescriptor, Buffer, response);
    close(FileDescriptor);
}
