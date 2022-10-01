#include "userreg.h"

uint8_t writeFile(FILE *fileSystem, USER_st user) {
	uint8_t bytesWritten;
	fileSystem = fopen("users.dat", "w");
	bytesWritten = fwrite(&user, sizeof(USER_st), 1, fileSystem);
	fclose(fileSystem);
	return bytesWritten;
}

uint8_t readFile(FILE *fileSystem, uint8_t max_users) {
	size_t i;
	uint8_t bytesRead;
	USER_st user_aux[max_users];
	fileSystem = fopen("users.dat", "r");
	bytesRead = fread(user_aux, sizeof(USER_st), max_users, fileSystem);
	fclose(fileSystem);
	for (i = 0; i < max_users; i++) printf("#%d | %s | %d | %.2f | %.2f\n", user_aux[i].ID, user_aux[i].name, user_aux[i].age, user_aux[i].height, user_aux[i].weight);
	return bytesRead;
}

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
