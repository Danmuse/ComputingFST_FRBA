// Author: Daniel Fabrizio Di Módica

// "<stdio.h>" "<stdlib.h>" "<stdbool.h>" "<string.h>" "<math.h>"
// "<fcntl.h>" "<pthread.h>" "<unistd.h>" "<sys/types.h>" "<sys/stat.h>"
// are included below...
#include "utils.h"
#include "sock-lib.h"

#define HOSTNAME_LEN 64
#define STATUS_SIZE 10
#define MAX_CLIENT 10

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

typedef struct {
	char hostname[HOSTNAME_LEN];
	int cpu;
	int mem;
} status_t;

// Shared resources
uint8_t threadCount = 0;
status_t client_status[STATUS_SIZE];

// Prototype functions
void *manageClient(void *);
void *checkArray(void *);
status_t strConvert(char *);
void regStatus(status_t *host);
void printHost(status_t);
char *str_trim(char *);

int main(int argc, char *argv[]) {
	int *sockdup, sockID;
	pthread_t threadCheck;
	struct sockaddr_in my_addr;
	// if (pthread_create(&threadCheck, NULL, checkArray, client_status))
	// 	perror("ERROR:: No se ha podido crear el Thread\n");
	// pthread_detach(threadCheck);
	if ((sockID = openConnection(&my_addr)) == -1) {
		perror("ERROR:: No se ha podido crear la conexión\n"); 
		exit(EXIT_FAILURE);
	}
        while (1) {
        	pthread_t threadID[MAX_CLIENT];
        	// Avoid segmentation fault
		if (threadCount < MAX_CLIENT) {
                	sockdup = (int *) malloc(sizeof(int));
			*sockdup = acceptRequest(sockID);
			pthread_mutex_lock(&mutex);
                       pthread_create(&threadID[threadCount], NULL, manageClient, sockdup);
                       pthread_detach(threadID[threadCount++]);
                       pthread_mutex_unlock(&mutex);
                }
                else usleep(100);
        }
	return EXIT_SUCCESS;
}

void *manageClient(void *arg) {
    size_t index;
    int *sockID = (int *) arg;
    uint16_t strLenght;
    char *strHost;
    
    read(*sockID, &strLenght, sizeof(uint16_t));
    
    // Initialize string handled
    strHost = (char *) malloc(ntohs(strLenght) + 1);
    memset(strHost, '\0', ntohs(strLenght) + 1);
    // read(*sockID, strHost, sizeof(ntohs(strLenght)));
    read(*sockID, strHost, ntohs(strLenght) + 1);
    strHost[ntohs(strLenght)] = '\0';
    printf("Recieved: %s\n", strHost);
    
    pthread_mutex_lock(&mutex);
    // for (index = 0; index < STATUS_SIZE; index++) 
    *client_status = strConvert(strHost);
    threadCount--;
    // if (clientAmmount < STATUS_SIZE)
    //     clientStatus[clientAmmount++] = status;
    pthread_mutex_unlock(&mutex);
    
    close(*sockID);
    free(arg);

    return NULL;
}

void *checkArray(void *arg) {
	size_t index; 
	status_t *host = (status_t *)arg;
	for (index = 0; index < STATUS_SIZE; index++) {
		if (index + 1 == STATUS_SIZE) regStatus(host);
		if (*(host[index].hostname) == '\0') index = 0;
    	}
	return NULL;
}

status_t strConvert(char *buffer) {
	char *token;
	status_t hostResult;
	// Initialize hostResult
	*(hostResult.hostname) = '\0'; hostResult.cpu = 0; hostResult.mem = 0;
	str_trim(buffer); // Delete '\n' at the end of the buffer string
	fprintf(stdout, "\nBuffer: \"%s\"\n", buffer);
	token = strtok(buffer, ";");
	if (token != NULL) strcpy(hostResult.hostname, token);
	token = strtok(NULL, ";");
	if (token != NULL) hostResult.cpu = atoi(token);
	token = strtok(NULL, ";");
	if (token != NULL) hostResult.mem = atoi(token);
	printHost(hostResult);
	return hostResult;
}

void regStatus(status_t *host) {
    size_t index;
    char *pathname = "../src/status.log";
    FILE *fileDescriptor = fopen(pathname, "a+");
    if (!fileDescriptor) perror("ERROR:: No se ha podido abrir el archivo\n");
    else { 
    fprintf(stdout, "Guardando cambios en \"%s\"\n", pathname);
    for (index = 0; index < STATUS_SIZE; index++) {
    	if (host[index].cpu > 50 || host[index].mem > 50)
        	fprintf(fileDescriptor, "Hostname: %s; CPU = %d%%; Memory = %d%%\n", host[index].hostname, host[index].cpu, host[index].mem);
    		*(host[index].hostname) = '\0'; host[index].cpu = 0; host[index].mem = 0;
    	}
    	fclose(fileDescriptor);
    	printf("Guardado exitoso!\n");
    }
}

void printHost(status_t host) {
	fprintf(stdout, "\nHost Name: %s", host.hostname);
	fprintf(stdout, "\nHost CPU: %d", host.cpu);
	fprintf(stdout, "\nHost Memory: %d\n", host.mem);
}

char *str_trim(char *str) {
	while (*str != '\0') {
		if (*str <= '\r') *str = '\0';
		str++;
	}
	return str;
}
