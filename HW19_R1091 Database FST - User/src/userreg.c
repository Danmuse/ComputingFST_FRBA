#include "userreg.h"

uint8_t chooseMenuOption(void) {
	uint8_t option;
	bool checkValidEntry;
	printf("Seleccione alguna opcion...\n");
	printf("[0] - Finalizar\n");
	printf("[1] - Cargar usuarios\n");
	printf("[2] - \n");
	printf("[3] - \n");
	
	while (!checkValidEntry) {
		printf("\nDefina su opcion: ");
		checkValidEntry = scanf("%hhu", &option);
		if (!checkValidEntry) {
			printf("Opcion invalida\n");
			while (getchar() != '\n');
		} else if (option > 3) {
			checkValidEntry = false;
			printf("Opcion invalida\n");
		}
	}
	return option;
}

bool checkEmptyFile(FILE *fileSystem) {
	long fileSize;
	fileSystem = fopen("users.bin", "rb");
	if (!fileSystem) {
		printf("El archivo al que se intenta acceder NO EXISTE\n");
		printf("Se ha generado un nuevo archivo \"users.bin\"\n");
		fileSystem = fopen("users.bin", "wb");
		fseek(fileSystem, 0L, SEEK_END);
		fileSize = ftell(fileSystem);
		printf("Tamano del archivo: %ld\n\n", fileSize);
		fclose(fileSystem);
		return EXIT_FAILURE;
	} else {
		printf("Se ha validado la existencia del archivo \"users.bin\"\n");
		fseek(fileSystem, 0L, SEEK_END);
		fileSize = ftell(fileSystem);
		printf("Tamano del archivo: %ld\n\n", fileSize);
		fclose(fileSystem);
		return fileSize != 0 ? EXIT_SUCCESS : EXIT_FAILURE;
	}
}

bool writeFile(FILE *fileSystem, USER_st *users, uint16_t max_users) {
	size_t i, bytesWritten;
	bool checkValidEntry;
	users = (USER_st *) malloc(max_users * sizeof(USER_st));
	fileSystem = fopen("users.bin", "wb");
	for (i = 0; i < max_users; i++) {
		(users + i) -> ID = (int) i + 1;
		printf("\nIngrese los datos del usuario #%d\n", (users + i) -> ID);
		
		printf("- Nombre: ");	
		clearBuffer((users + i) -> name);
		fgets((users + i) -> name, sizeof((users + i) -> name), stdin);
		// clearBuffer((users + i) -> name); // If you entried an unlimited string before
		
		while (!checkValidEntry) {
			printf("- Edad: ");
			checkValidEntry = scanf("%d", &((users + i) -> age));
			if (!checkValidEntry) {
				printf("Error, reingrese el dato\n");
				while (getchar() != '\n');
			}
		}
		checkValidEntry = false;
		
		while (!checkValidEntry) {
			printf("- Altura: ");
			checkValidEntry = scanf("%f", &((users + i) -> height));
			if (!checkValidEntry) {
				printf("Error, reingrese el dato\n");
				while (getchar() != '\n');
			}
		}
		checkValidEntry = false;
		
		while (!checkValidEntry) {
			printf("- Peso: ");
			checkValidEntry = scanf("%f", &((users + i) -> weight));
			if (!checkValidEntry) {
				printf("Error, reingrese el dato\n");
				while (getchar() != '\n');
			}
		}
		checkValidEntry = false;
		
		bytesWritten = fwrite((users + i), sizeof(USER_st), 1, fileSystem);
		if (!bytesWritten) {
			users = (USER_st *) realloc(users, i * sizeof(USER_st));
			return EXIT_FAILURE;
		}
	}
	fclose(fileSystem);
	return EXIT_SUCCESS;
}

bool loadFile(FILE *fileSystem, USER_st *users) {
	size_t i, bytesRead;
	
	fileSystem = fopen("users.bin", "rb");
	for (i = 0; !feof(fileSystem); i++) {
		users = (USER_st *) realloc(users, i * sizeof(USER_st));
		fread((users + i), sizeof(USER_st), 1, fileSystem);
	}
	fclose(fileSystem);
	return EXIT_SUCCESS;
}

/*
bool readFile(FILE *fileSystem, uint16_t max_users) {
	size_t i;
	uint8_t bytesRead;
	USER_st user_aux[max_users];
	fileSystem = fopen("users.bin", "rb");
	bytesRead = fread(user_aux, sizeof(USER_st), max_users, fileSystem);
	fclose(fileSystem);
	for (i = 0; i < max_users; i++) printf("#%d | %s | %d | %.2f | %.2f\n", user_aux[i].ID, user_aux[i].name, user_aux[i].age, user_aux[i].height, user_aux[i].weight);
	return bytesRead;
}
*/

void clearBuffer(char *buffer) { if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); }

// loadUsers

// showContent

/*

void imprimirPersona(USER_st *persona) {
    printf("ID: %d\n", persona -> id);
    printf("Nombre: %s\n", persona -> name);
    printf("Edad: %d\n", persona -> age);
    printf("Altura: %.2f\n", persona -> height);
    printf("Peso: %.2f\n", persona -> weight);
}

// Returns -1 if error
int escribirPersonaEnArchivo(USER_st *persona, FILE *file) {
    int bytesWritten = fwrite(persona, sizeof(USER_st), 1, file);
    return (!bytesWritten) ? -1 : 0;
}

// Returns -1 if error
int leerPersonaPorId(FILE *file, int id, USER_st *persona) {
    int bytesRead;
    fseek(file, (id - 1) * sizeof(USER_st), SEEK_SET);
    bytesRead = fread(persona, sizeof(USER_st), 1, file);
    return (!bytesRead) ? -1 : 0;
}

// Returns -1 if error
int escribirArrayPersonasEnArchivo(USER_st personas[], int arraySize, FILE *file) {
    int bytesWritten = fwrite(personas, sizeof(USER_st), arraySize, file);
    return (bytesWritten != arraySize) ? -1 : 0;

}

// Expects pointer has memory allocated for at least one element, returns the ammount of elements found but -1 if you don't have enough memory
int leerArrayDePersonasDeArchivo(FILE *file, USER_st **personasSalida) {
    int readenBytes = 1;
    int i = 0;;

    while (readenBytes == 1) {
        readenBytes = fread((*personasSalida) + i++, sizeof(USER_st), 1, file);
        *personasSalida = (USER_st *) realloc(*personasSalida, sizeof(USER_st) * (i + 1));
        if (*personasSalida == 0) {
            i = 0;
            readenBytes = -1;
        }
    }
    // Dejo el espacio limite para las personas existentes
    *personasSalida = (USER_st *) realloc(*personasSalida, sizeof(USER_st) * (i - 1));
    return i - 1;
}

void inicializarPersonaPorTeclado(USER_st *persona, int id) {
    persona->id = id;
    printf("Ingrese el nombre de la persona\n");
    scanf("%s", (persona -> name));
    printf("Ingrese la edad de la persona\n");
    scanf("%d", &(persona -> age));
    printf("Ingrese la altura de la persona(en metros)\n");
    scanf("%f", &(persona -> height));
    printf("Ingrese el peso de la persona(en Kgf)\n");
    scanf("%f", &(persona -> weight));
}

// Returns -1 if person wasn't found
int buscarPersonaPorNombre(USER_st personas[], int arraySize, char *name, USER_st *personaEncontrada) {
    int i;
    bool found = false;

    for (i = 0; i < arraySize && !found; i++) {
        if (!strcmp(personas[i].name, name)) {
            *personaEncontrada = personas[i];
            found = true;
        }
    }
    return (found) ? 0 : -1;
}

int editarEntradaConId(int id, FILE *file, USER_st *personas) {
    fseek(file, (id - 1) * sizeof(USER_st), SEEK_SET);
    inicializarPersonaPorTeclado((personas + (id - 1)), id);
    escribirPersonaEnArchivo((personas + (id - 1)), file);
}

*/
