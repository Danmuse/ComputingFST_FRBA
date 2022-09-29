/******************************************************************************************************************************
 * a) Leer y escribir una estructura PERSON en un archivo                                                                     *
 * b) Leer y escribir un array de estructuras PERSON en un archivo                                                            *
 * c) Leer y escribir un array de punteros a estructuras PERSON. El array con memoria dinamica                                *
 * d) Hacer un menu con las siguientes opciones:                                                                              *
 *	1) Cargar, 2) Buscar por nombre, 3) Buscar por ID                                                                     *
 * Cuando el programa inicia carga la informacion desde el archivo.                                                           *
 * e) Modificar el programa anterior para que la base de datos este ordena siempre por ID.                                    *
 * Cuando se cargue un nuevo elemento se inserte ordenado                                                                     *
 * f) Modificar la funciona de buscar por ID para que sea eficiente con la premisa que la base de datos esta ordenada (fseek) *
 * g) Implementar funcionar que modifica un registro por ID                                                                   *
 ******************************************************************************************************************************/

#include <stdio.h>

typedef struct {
    int id;
    char nombre[STR_NAME_LEN];
    int edad;
    float altura;
    float peso;
} PERSON;

int main(void) {
    PERSON p = { "Juan", 12, 1.40, 40};
    PERSON q;

    escribir(p, fp);
    leer(fp, 1);
    imprimir(q);

    return 0;
}
