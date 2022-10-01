#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 50

int main(void) {
	FILE *fileSystem;
	char buffer[MAX_SIZE];
	char *token;

	fileSystem = fopen("example.csv", "r");
	if (!fileSystem) exit(EXIT_FAILURE);
	// Tener en cuenta que se incluye el '\n'
	while (fgets(buffer, sizeof(buffer), fileSystem) != NULL) {
		printf("buffer = %s", buffer);
		// Borrar el '\n' si existe...
		token = strtok(buffer, ","); // Save only the first token of line
		printf("Simple token = %s\n", token);
		while (token != NULL) {
			token = strtok(NULL, ","); // Save the rest tokens of the same line
			if (token != NULL)
				printf("Full token = %s\n", token);
		}
	}
	printf("=== END ===\n");
	fclose(fileSystem);
	return EXIT_SUCCESS;
}
