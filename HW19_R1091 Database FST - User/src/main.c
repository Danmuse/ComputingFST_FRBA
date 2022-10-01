/******************************************************************************************************************************
 * a) Leer y escribir una estructura USER en un archivo                                                                       *
 * b) Leer y escribir un array de estructuras USER en un archivo                                                              *
 * c) Leer y escribir un array de punteros a estructuras USER. El array con memoria dinamica                                  *
 * d) Hacer un menu con las siguientes opciones:                                                                              *
 *	1) Cargar, 2) Buscar por nombre, 3) Buscar por ID                                                                     *
 * Cuando el programa inicia carga la informacion desde el archivo.                                                           *
 * e) Modificar el programa anterior para que la base de datos este ordena siempre por ID.                                    *
 * Cuando se cargue un nuevo elemento se inserte ordenado                                                                     *
 * f) Modificar la funciona de buscar por ID para que sea eficiente con la premisa que la base de datos esta ordenada (fseek) *
 * g) Implementar una funcion que modifica un registro por ID                                                                 *
 ******************************************************************************************************************************/

// "<stdio.h>" "<stdlib.h>" "<string.h>" "<stdbool.h>" "USER_st" are included below...
#include <userreg.h>

int main(void) {
	size_t i;
	USER_st *users;
	FILE *fileSystem;
	uint8_t max_users, response;
	bool request_status = true, menu_status = true;
	
	if (request_status) {
		printf("Ingrese la cantidad de usuarios deseados: ");
		scanf("%hhu", &max_users);
		if (max_users < 255) {
			request_status = false;
			users = (USER_st *) malloc(max_users * sizeof(USER_st));
			if (!users) exit(EXIT_FAILURE);
		} else printf("Ha excedido la cantidad de usuarios... [255]\n");
	}
	
	while (menu_status) {
		for (i = 0; i < max_users; i++) {
			(users + i) -> ID = (int) i;
			printf("Ingrese los datos del usuario #%ld\n", i);
			printf("- Nombre: ");
			scanf("%s", (users + i) -> name);
			printf("- Edad: ");
			scanf("%d", &((users + i) -> age));
			printf("- Altura: ");
			scanf("%f", &((users + i) -> height));
			printf("- Peso: ");
			scanf("%f", &((users + i) -> weight));
			response = writeFile(fileSystem, *(users + i));
			if (!response) break;
		}
		response = readFile(fileSystem, max_users);
		menu_status = false;
	}
	free(users);
	return EXIT_SUCCESS;
}

/*

int main(void) {
    USER_st *users, user_finded;
    FILE *filesystem;
    int max_users;
    bool request_state = true, menu_state = true;
    int opcionMenu;
    char personaABuscar[MAX_NAME_LENGTH];
    int idABuscar;
    int errCode;

    printf("Indique cual es la cantidad maxima de usuarios que desea ingresar: ");
    scanf("%hhu", &max_users);
    if (request_state) {
        if (max_users < 254) {
            request_state = false;
            users = (USER_st *) malloc(max_users * sizeof(USER_st));
            if (!users) exit(1);
            printf("La memoria ha almacenado espacio para ingresar %hhu usuarios\n", max_users);
        } else printf("Ha excedido el limite de usuarios... [255]\n");
    }
    
    filesystem = fopen("users.dat", "r");
    if (filesystem) {
        max_users = leerArrayDePersonasDeArchivo(filesystem, &users);
        fclose(filesystem);
    }
    else users = (USER_st *) realloc(users, 0);
    
    while (menu_state) {
        printf("========================================\n"
               "Elija alguna de las siguientes opciones:\n"
               "1) Cargar persona\n"
               "2) Buscar persona por nombre\n"
               "3) Buscar persona por id\n"
               "4) Editar una persona\n"
               "5) Salir del menu\n"
               "========================================\n");
        scanf("%d", &opcionMenu);
        switch (opcionMenu) {
            case 1:
                if (!users) {
                    users = (USER_st *) malloc(sizeof(USER_st));
                    max_users = 1;
                }
                else users = (USER_st *) realloc(users, sizeof(USER_st) * ++max_users);
                filesystem = fopen("users.dat", "a");
                if (users) {
                    inicializarPersonaPorTeclado(&users[max_users - 1], max_users);
                    if (!filesystem) return -2;
                    escribirPersonaEnArchivo(&users[max_users - 1], filesystem);
                    fclose(filesystem);
                }
                else printf("Mallok es mallo\n");
                break;
            case 2:
                printf("Ingrese el nombre de la persona a buscar\n");
                scanf("%s", personaABuscar);
                if (users) {
                    filesystem = fopen("users.dat", "r");
                    errCode = buscarPersonaPorNombre(users, max_users, personaABuscar, &personaEncontrada);
                    fclose(filesystem);
                    if (errCode != -1) {
                        printf("Persona encontrada, sus datos son:\n");
                        imprimirPersona(&personaEncontrada);
                    }
                    else printf("La persona no está registrada\n");
                }
                else printf("El array está vacío maestro\n");
                break;
            case 3:
                printf("Ingrese el id de la persona a buscar\n");
                scanf("%d", &idABuscar);
                if (users) {
                    filesystem = fopen("users.dat", "r");
                    errCode = leerPersonaPorId(filesystem, idABuscar, &personaEncontrada);
                    fclose(filesystem);
                    if (errCode != -1) {
                        printf("Persona encontrada, sus datos son:\n");
                        imprimirPersona(&personaEncontrada);
                    }
                    else printf("La persona no esta registrada\n");
                }
                else printf("El array está vacío maestro\n");
                break;
            case 4:
                printf("Ingrese el ID de la persona a editar\n");
                scanf("%d", &idABuscar);
                filesystem = fopen("users.dat", "r+");
                if (!filesystem) return -3;
                editarEntradaConId(idABuscar, filesystem, users);
                fclose(filesystem);
                break;
            case 5:
                menu_state = false;
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }

    }
    free(users);
    return EXIT_SUCCESS;
}

*/
