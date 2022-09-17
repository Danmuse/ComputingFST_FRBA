#include "student.h"

my_boolean enter_struct(student_t *students) {
	printf("Ingrese el nombre del alumno: ");
	scanf("%s", students -> name);
	printf("Ingrese el apellido del alumno: ");
	scanf("%s", students -> surname);
	printf("Ingrese el legajo del alumno: ");
	scanf("%hu", &students -> docket);
	printf("Ingrese la edad del alumno: ");
	scanf("%hhu", &students -> age);
	return check_exit(students); // Dejar de ejecutar el ingreso de alumnos
}

my_boolean check_exit(student_t *students) {
	my_boolean output = FALSE;
	if (*(students -> name) < 'A' || *(students -> surname) < 'A' || !(students -> docket) || !(students -> age)) output = TRUE;
	return output;
}

void show_struct(student_t *students) {
	printf("\nEl nombre del alumno es %s\n", students -> name);
	printf("El apellido del alumno es %s\n", students -> surname);
	printf("El legajo del alumno es %hu\n", students -> docket);
	printf("La edad del alumno es %hhu\n", students -> age);
}
