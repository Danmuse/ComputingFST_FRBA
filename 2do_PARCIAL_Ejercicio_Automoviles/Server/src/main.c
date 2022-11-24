// Author: Daniel Fabrizio Di Módica
// Title: Ejercicio Automoviles

// "<stdio.h>" "<stdlib.h>" "<stdbool.h>" "<string.h>" "<math.h>"
// "<fcntl.h>" "<pthread.h>" "<unistd.h>" "<sys/types.h>" "<sys/stat.h>"
// are included below...
#include "utils.h"
#include "autopart_list.h"
#include "sock-lib.h"

void clearBuffer(char *buffer);
void showPart(autopart_st *);
char *str_trim(char *);

int main(int argc, char *argv[]) {
	char buffer[MAX_SIZE_STR];
	if (argc == 2) {
		char *token;
		size_t index = 0;
		autopart_st *part;
		LIST_st *inventory;
		int inventoryItems = 0;
		FILE *fileDescriptor = fopen(argv[1], "rb");
		if (!fileDescriptor) {
			perror("ERROR:: No se ha podido abrir el archivo .csv\n");
			exit(EXIT_FAILURE);
		} 
		// WARNING: '\n' character is included at the end of each .csv line!!
		while (fgets(buffer, sizeof(buffer), fileDescriptor) != NULL) {
			str_trim(buffer); // Delete '\n' at the end of the buffer string
			fprintf(stdout, "\nBuffer: \"%s\"", buffer);
			token = strtok(buffer, ";");
			fprintf(stdout, "\nToken: \"%s\"", token);
			if (strcmp(token, "Part Number") && token != NULL) part -> number = atoi(token);
			else continue;
			token = strtok(NULL, ";");
			if (token != NULL) strcpy(part -> name, token);
			else continue;
			token = strtok(NULL, ";");
			if (token != NULL) part -> amount = atoi(token);
			else continue;
			token = strtok(NULL, ";");
			if (token != NULL) part -> price = (float)atof(token);
			else continue;
			showPart(part);
			if (index == 0) InsertTop(inventory, part);
			else InsertAfter(index - 1, inventory, part);
			index++;
		}
		fclose(fileDescriptor);
		inventoryItems = ListLenght(inventory);
		fprintf(stdout, "\nLa cantidad de productos en la Lista: %d\n", inventoryItems);
		for (index = 0; index < inventoryItems; index++) FreeNode(inventory -> header); // WATCH OUT!!
		return EXIT_SUCCESS;
	} else {
		perror("ERROR:: Debe especificar la ruta del archivo .csv\n");
		exit(EXIT_FAILURE);
	}

	/*
	int sockfd; // File Descriptor del socket por el que el servidor "escuchará" conexiones
	char message[] = "Hello, world!";
	struct sockaddr_in my_addr; // Contendrá la dirección IP y el número de puerto local
	int sockdup; 

	if ((sockfd = openConnection(&my_addr)) == -1) {
		perror ("Falló la creación de la conexión"); 
		exit (1);
	}

	while (1) {
		sockdup = acceptRequest(sockfd);
		// Aca se pone un fork() y se lo convierte en un server concurrente
		// En tal caso, lo que sigue es el child process
		// El padre vuelve a Aceptar_pedidos
		fork();
		if (write(sockdup, message , sizeof(message)) == -1) {
			perror("Error escribiendo mensaje en socket");
			exit (1);
		}
		close(sockdup);
	}
	*/
}

void clearBuffer(char *buffer) {
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
}

void showPart(autopart_st *part) {
	fprintf(stdout, "\nP/N: #%d", part -> number);
	fprintf(stdout, "\nPart Name: %s", part -> name);
	fprintf(stdout, "\nPart Quantity: %d\n", part -> amount);
	fprintf(stdout, "\nPart Price: %.2f\n", part -> price);
}

char *str_trim(char *str) {
	while (*str != '\0') {
		if (*str < 32) *str = '\0';
		str++;
	}
	return str;
}
