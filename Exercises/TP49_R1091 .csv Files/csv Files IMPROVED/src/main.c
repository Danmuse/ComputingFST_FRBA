#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50
#define MAX_USERS 19

typedef struct {
	int ID;
	char *name;
	char *genre;
} USER_st;

char* str_trim(char*);
void print_users(USER_st *);

int main(void) {
	// USER_st *users = NULL; TODO
	USER_st *users;
	FILE *fileSystem;
	char buffer[MAX_SIZE];
	char *token;
	size_t index = 0;
	
	users = (USER_st *) malloc(MAX_USERS * sizeof(USER_st));
	if (!users) exit(EXIT_FAILURE);
	
	fileSystem = fopen("example.csv", "r");
	if (!fileSystem) exit(EXIT_FAILURE);
	// WARNING: '\n' character is included at the end of each .csv line!!
	while (fgets(buffer, sizeof(buffer), fileSystem) != NULL) {
		str_trim(buffer); // Delete '\n' at the end of the buffer string
		printf("\nbuffer = \"%s\"", buffer);
		
		/*
		It is not possible to reallocate a new memory space without linked lists TODO
		if (!users) { // Store memory...
			users = (USER_st *) malloc(++users_max * sizeof(USER_st));
			if (!users) exit(EXIT_FAILURE);
		} else {
			users = (USER_st *) realloc(users, ++users_max * sizeof(USER_st));
			if (!users) exit(EXIT_FAILURE);
		}
		*/
		
		// token = strtok(NULL, ",");
		// (users + index) -> ID = (token != NULL) ? atoi(token) : 0;
		// token = strtok(NULL, ",");
		// (users + index) -> name = (token != NULL) ? token : '\0';
		// token = strtok(NULL, ",");
		// (users + index) -> genre = (token != NULL) ? token : '\0';
		
		token = strtok(buffer, ",");
		if (strcmp(token, "ID") && token != NULL) (users + index) -> ID = atoi(token);
		else continue;
		token = strtok(NULL, ",");
		(users + index) -> name = (char *) malloc((strlen(token) + 1) * sizeof(char));
		if (token != NULL) strcpy((users + index) -> name, token);
		else continue;
		token = strtok(NULL, ",");
		(users + index) -> genre = (char *) malloc((strlen(token) + 1) * sizeof(char));
		if (token != NULL) strcpy((users + index) -> genre, token);
		else continue;
		print_users(users + index);
		index++;
	}
	printf("=== END ===\n\n");
	fclose(fileSystem);
	printf("Se han generado las siguientes estructuras...\n");
	for (index = 0; index < MAX_USERS; index++) {
		print_users(users + index);
		free((users + index) -> name);
		free((users + index) -> genre);
	}
	free(users);
	return EXIT_SUCCESS;
}

void print_users(USER_st *user) {
	printf("\nID: #%d", user -> ID);
	printf("\nName: %s", user -> name);
	printf("\nGenero: %s\n", user -> genre);
}

char *str_trim(char *str) {
	while (*str != '\0') {
		if (*str == '\n') *str = '\0';
		str++;
	}
	return str;
}
