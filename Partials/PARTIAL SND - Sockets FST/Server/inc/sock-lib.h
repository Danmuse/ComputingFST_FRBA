#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <netdb.h>

#define PORT 8000	/* El puerto donde se conectará, servidor */
#define BACKLOG 10	/* Tamaño de la cola de conexiones recibidas */

int connecting(int, char **);

int openConnection(struct sockaddr_in *); /* Función que crea la conexión*/

int acceptRequest(int); /* Función que acepta una conexión entrante*/
