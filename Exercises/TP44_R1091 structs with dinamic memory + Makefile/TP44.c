/*******************************************************************************************
 * Desarrolle un programa que permita ingresar el nombre, apellido, legajo y edad          *
 * de un maximo de alumnos especificado por el usuario. En caso de que se ingrese un valor *
 * invalido para alguno de estos atributos, entonces finalizara el ingreso de alumnos      *
 *******************************************************************************************/

#include "student.h"

// void *malloc(size_t size); // Function define inner libc

// In program you've to write...
// 	int a = 5;
// 	int *vec;
//	vec = (int *) malloc(a * sizeof(int));
//	if (!vec /* vec == NULL */) exit(0);
// 	Process the rest of code and finish with "free(vec);"

int main(void) {
	size_t i, j;
	uint8_t MAX_STUDENTS;
	uint8_t confirm;
	student_t *students;
	
	printf("Ingrese la cantidad de alumnos: ");
	scanf("%hhu", &MAX_STUDENTS);
	students = (student_t *) malloc(MAX_STUDENTS * sizeof(student_t));
	if (!students) exit(0);
	
	printf("¿Desea redefinir la cantidad de alumnos?\nIngrese '0' para NO y '1' para SI\n");
	scanf("%hhu", &confirm);
	if (confirm) {
		printf("Ingrese la cantidad de alumnos: ");
		scanf("%hhu", &MAX_STUDENTS);
		students = (student_t *) realloc(students, MAX_STUDENTS * sizeof(student_t));
	}
	
	for (i = 0; i < MAX_STUDENTS; i++) {
		printf("\nIngrese los datos del alumno #%ld\n", i);
		if (enter_struct(&students[i])) break;
	}
	if (i == MAX_STUDENTS) printf("\n--- Se ha ingresado el limite de alumnos ---\n");
	for (j = 0; j < i; j++) show_struct(&students[j]);
	free(students);
	return EXIT_SUCCESS;
}
