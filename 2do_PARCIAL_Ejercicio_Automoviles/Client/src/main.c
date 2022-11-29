// Author: Daniel Fabrizio Di Módica

// "<stdio.h>" "<stdlib.h>" "<stdbool.h>" "<string.h>" "<math.h>"
// "<fcntl.h>" "<pthread.h>" "<unistd.h>" "<sys/types.h>" "<sys/stat.h>"
// are included below...
#include "utils.h"
#include "sock-lib.h"

#define MAX_SIZE_STR 100
#define MAX_COMMAND_SIZE 7

typedef struct {
	int number;
	char name[MAX_SIZE_STR];
	int amount;
	float price;
} autopart_st;

typedef struct node_st {
	autopart_st autopart;
	struct node_st* next;
} NODE_st;

int main(int argc, char *argv[]) {
    int sockID;
    char command[MAX_COMMAND_SIZE];
    char response;
    autopart_st *foundElement = (autopart_st *) malloc(sizeof(autopart_st));
    uint8_t partNumber;

    if (argc == 4) {
        sockID = connecting(2, argv);
        strcpy(command, argv[2]);
        write(sockID, command, sizeof(command));

        partNumber = atoi(argv[3]);
        partNumber = htonl(partNumber);
        if (!strcmp(command, "order")) {
            write(sockID, &partNumber, sizeof(partNumber));
            read(sockID, &response, sizeof(char));

            if (response == 'w') printf("Operación realizada con éxito\n");
            else printf("Operación fallida\n");
        }
        else if (!strcmp(command, "search")) {
            write(sockID, &partNumber, sizeof(partNumber));
            read(sockID, &response, sizeof(char));
            
            if (response == 'w') {
                read(sockID, foundElement, sizeof(autopart_st));
                printf("El elemento que pidió es el siguiente\n"
                       "Número de parte: %d\n"
                       "Nombre de parte: %s\n"
                       "Cantidad en stock: %d\n"
                       "Precio: %0.2f\n", foundElement -> number, foundElement -> name, foundElement -> amount,
                       foundElement -> price);
                free(foundElement);
            }
            else printf("El elemento que pidió no se encuentra en stock\n");
        }
        else if (!strcmp(command, "delete")) {
            write(sockID, &partNumber, sizeof(partNumber));
            read(sockID, &response, sizeof(char));
            if (response == 'w') printf("Operación realizada con éxito\n");
            else printf("Operación fallida\n");
        }
        else {
            printf("Comando equivocado\n"
                   "Opciones disponibles:\n"
                   "  - search   (Dada un número de parte lista todos los datos del artículo)\n"
                   "  - order    (Dado un número de parte baja en 1 la cantidad de stock)\n"
                   "  - delete   (Dado un número de parte lo elimina de la lista)\n");
        }
        close(sockID);
    }
    else printf("Usage: ./clientAutopartes <hostname> <command> <argument>\n");
    return EXIT_SUCCESS;
}
