#include "sock-lib.h"

#define MAX_DATASIZE 4096 // Máxima cantidad de bytes que puede recibir en una transacción

int main(int argc, char *argv[]) {
	int sockfd; // File Descriptor para sockets
	int numbytes; // Contendrá el número de bytes recibidos por read()
	char buf[MAX_DATASIZE]; // Buffer donde se reciben los datos de read()

// Tratamiento de la línea de comandos
	if (argc < 2) {
		fprintf(stderr,"Uso: %s hostname [port]\n", argv[0]);
		exit(1);
        }
	sockfd = connecting(argc, argv);

// Recibimos los datos del servidor
	if ((numbytes = read(sockfd, buf, MAX_DATASIZE)) == -1) {
		perror("Error de lectura en el socket");
		exit(1);
	}

// Visualizamos lo recibido
	buf[numbytes] = '\0';
	printf("Recibido: %s\n", buf);

// Devolvemos recursos al sistema
	close(sockfd);
	return 0;
}
