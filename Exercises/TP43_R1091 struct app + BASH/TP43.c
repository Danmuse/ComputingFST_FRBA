/***************************************************************************************
 * Desarrolle un programa que permita ingresar el nombre, apellido, legajo y edad      *
 * de un maximo de 50 alumnos. En caso de que se ingrese un valor invalido para alguno *
 * de estos atributos, entonces finalizara el ingreso de alumnos                       * 
 ***************************************************************************************/

#include "student.h"
#define MAX_STUDENTS 50

int main(void) {
	size_t i, j;
	student_t students[MAX_STUDENTS];
	for (i = 0; i < MAX_STUDENTS; i++) {
		printf("\nIngrese los datos del alumno #%ld\n", i);
		if (enter_struct(&students[i])) break;
	}
	if (i == MAX_STUDENTS) printf("\n--- Se ha ingresado el limite de alumnos ---\n");
	for (j = 0; j < i; j++) show_struct(&students[j]);
	return EXIT_SUCCESS;
}
