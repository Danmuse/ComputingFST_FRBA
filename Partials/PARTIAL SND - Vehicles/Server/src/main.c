// Author: Daniel Fabrizio Di Módica
// Title: Ejercicio Automoviles

// "<stdio.h>" "<stdlib.h>" "<stdbool.h>" "<string.h>" "<math.h>"
// "<fcntl.h>" "<pthread.h>" "<unistd.h>" "<sys/types.h>" "<sys/stat.h>"
// are included below...
#include "utils.h"
#include "autopart_list.h"
#include "sock-lib.h"

#define MAX_CLIENTS 5
#define MAX_PART_NAME 100
#define MAX_COMMAND_SIZE 7

// Shared resources
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
uint8_t threadCount = 0;
char *pathname; // Path of file descriptor
LIST_st inventory;

// Prototype functions
static void *manageClient(void *);
void handleClose(int);
LIST_st createList(char *);
void clearBuffer(char *);
void showPart(autopart_st);
char *str_trim(char *);

int isPartNumberEqual(NODE_st *, NODE_st *);
int order(NODE_st *, LIST_st *);
NODE_st *search(int);

int main(int argc, char *argv[]) {
	pathname = argv[1];
	int *sockdup, sockfd;
	struct sockaddr_in my_addr;
	if ((sockfd = openConnection(&my_addr)) == -1) {
		perror("ERROR:: No se ha podido crear la conexión\n"); 
		exit(EXIT_FAILURE);
	}
	
	if (argc == 2) {
		pthread_t threadID[MAX_CLIENTS];
		inventory = createList(pathname);
		// showList(inventory);
		
		// Ctrl + C to save changes
		signal(SIGINT, handleClose);
		
		while (1) {
			// Avoid Segmentation Fault
            		if (threadCount < MAX_CLIENTS) {
                		// Socket isn't amenable to changes by multithreading
                		sockdup = (int *) malloc(sizeof(int));
                		*sockdup = acceptRequest(sockfd);
				// Avoid exceeding the maximum amount of clients allowed
                		pthread_mutex_lock(&mutex);
                		pthread_create(&threadID[threadCount], NULL, manageClient, sockdup);
                		pthread_detach(threadID[threadCount++]);
                		pthread_mutex_unlock(&mutex);
            		} else usleep(100);
            	}
		
		FreeList(&inventory);
		fprintf(stdout, "\nCantidad de productos en la lista: %d\n", ListLenght(&inventory));
	} else {
		perror("ERROR:: Debe especificar la ruta del archivo .csv\n");
		exit(EXIT_FAILURE);
	}
	return EXIT_SUCCESS;
}

void clearBuffer(char *buffer) {
	if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); 
}

void handleClose(int signal) {
    // FILE *fileDescriptor = fopen(pathname, "wb");
    FILE *fileDescriptor = fopen("../assets/output.csv", "wb");
    if (!fileDescriptor) {
	perror("ERROR:: No se han guardado los cambios en el archivo .csv\n");
	exit(EXIT_FAILURE);
    } else fprintf(stdout, "Guardando cambios en \"%s\"\n", pathname);
    fprintf(fileDescriptor, "Part Number;Part Name;Part Quantity;Part Price\n");
    while (inventory.header != NULL) {
        fprintf(fileDescriptor, "%d;%s;%d;%.2f\n", inventory.header -> autopart.number, inventory.header -> autopart.name,
                inventory.header -> autopart.amount, inventory.header -> autopart.price);
        inventory.header = inventory.header -> next;
    }
    fclose(fileDescriptor);
    printf("Guardado exitoso!\n");
    exit(EXIT_SUCCESS);
}

static void *manageClient(void *arg) {
    int *sockID = (int *)arg;
    unsigned int partNumber;
    char command[MAX_COMMAND_SIZE], status;
    NODE_st *part = (NODE_st *) malloc(sizeof(NODE_st));

    read(*sockID, command, sizeof(command));

    // Server:: Hey Client! Type "order" to discount an item from inventory
    if (!strcmp(command, "order")) {
        read(*sockID, &partNumber, sizeof(partNumber));
        partNumber = ntohl(partNumber);

        part -> autopart.number = partNumber;

	fprintf(stdout, "Part Number: %d\n", partNumber);

        // 'b' === Bad // 'w' === Well //
        if (order(part, &inventory) == -1) status = 'b';
        else status = 'w';
        write(*sockID, &status, 1);
    }
    
    // Server:: Hey Client! Type "search" to obtain the characteristics of some part
    else if (!strcmp(command, "search")) {
        read(*sockID, &partNumber, sizeof(partNumber));
        // "Network to Host" --- (unsigned short/long/int)
        // Leer: ntohl
        // Escritura: htonl
        partNumber = ntohl(partNumber);

	// Check if "part" is NULL
        if ((part = search(partNumber))) {
            status = 'w';
            write(*sockID, &status, 1);
            write(*sockID, part, sizeof(NODE_st));
        }
        else {
            status = 'b';
            write(*sockID, &status, 1);
        }
    }
    
    // Server:: Hey Client! You typed an invalid function
    else {
        status = 'x';
        write(*sockID, &status, 1);
    }

    close(*sockID);
    free(arg);
    free(part);

    pthread_mutex_lock(&mutex);
    threadCount--;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

// Decreaces stock by 1 when possible, returns -1 if stock is already zero
int order(NODE_st *product, LIST_st *inventory) {
    int errCode = 1;
    while (inventory -> header != NULL) {
        if (isPartNumberEqual(product, inventory -> header)) {
            if (inventory -> header -> autopart.amount != 0) {
                pthread_mutex_lock(&mutex);
                inventory -> header -> autopart.amount--;
                pthread_mutex_unlock(&mutex);
            }
            else errCode = -1;
        }
        inventory -> header = inventory -> header -> next;
    }
    return errCode;
}

// Returns NULL if it is not in the list
NODE_st *search(int partNumber) {
    NODE_st *foundElement = (NODE_st *) malloc(sizeof(NODE_st));
    NODE_st *head = (NODE_st *) malloc(sizeof(LIST_st));
    foundElement -> autopart.number = partNumber;

    // Store the header reference
    head = inventory.header;

    while (head) {
        if (isPartNumberEqual(foundElement, head)) {
            strcpy(foundElement -> autopart.name, head -> autopart.name);
            foundElement -> autopart.amount = head -> autopart.amount;
            foundElement -> autopart.price = head -> autopart.price;
            return foundElement;
        }
        head = inventory.header -> next;
    }
    return NULL;
}

// Compares if two parts are the same based on partNumber. Returns 0 if false
int isPartNumberEqual(NODE_st *a, NODE_st *b) {
    return (a -> autopart.number) == (b -> autopart.number);
}

LIST_st createList(char *file) {
	char *token;
	size_t index = 0;
	autopart_st part;
	LIST_st products;
	char buffer[MAX_SIZE_STR];
	FILE *fileDescriptor = fopen(file, "rb");
	if (!fileDescriptor) {
		perror("ERROR:: No se ha podido abrir el archivo .csv\n");
		exit(EXIT_FAILURE);
	}
	rewind(fileDescriptor);
	// WARNING: '\n' character is included at the end of each .csv line!!
	while (fgets(buffer, sizeof(buffer), fileDescriptor) != NULL) {
		str_trim(buffer); // Delete '\n' at the end of the buffer string
		// fprintf(stdout, "\nBuffer: \"%s\"", buffer);
		token = strtok(buffer, ";");
		if (strcmp(token, "Part Number") && token != NULL) part.number = atoi(token);
		else continue;
		token = strtok(NULL, ";");
		if (token != NULL) strcpy(part.name, token);
		else continue;
		token = strtok(NULL, ";");
		if (token != NULL) part.amount = atoi(token);
		else continue;
		token = strtok(NULL, ";");
		if (token != NULL) part.price = (float)atof(token);
		else continue;
		// showPart(part);
		if (index == 0) InsertTop(&products, &part);
		else InsertAfter(index - 1, &products, &part);
		index++;
	}
	fclose(fileDescriptor);
	fprintf(stdout, "\nCantidad de productos en la lista: %d\n", ListLenght(&products));
	return products;
}

void showPart(autopart_st part) {
	fprintf(stdout, "\nP/N: %d", part.number);
	fprintf(stdout, "\nPart Name: %s", part.name);
	fprintf(stdout, "\nPart Quantity: %d", part.amount);
	fprintf(stdout, "\nPart Price: %.2f\n", part.price);
}

char *str_trim(char *str) {
	while (*str != '\0') {
		if (*str <= '\r') *str = '\0';
		str++;
	}
	return str;
}
