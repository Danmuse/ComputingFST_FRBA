#include <stdio.h>
#include <string.h>
#define SIZE 20

typedef struct {
	char name[SIZE];
	int category;
	float height;
	int age;
} whoami_t;

typedef union {
	char name[SIZE];
	int category;
	float height;
	int age;
} whoami_u;

int main(void) {
	whoami_t person_t;
	whoami_u person_u;
	strcpy(person_t.name, "Daniel");
	strcpy(person_u.name, "Daniel");
	person_t.category = 9;
	person_u.category = 9;
	person_t.height = 175.3;
	person_u.height = 175.3;
	person_t.age = 65;
	person_u.age = 65;
	printf("\n--- STRUCT content ---\n");
	printf("Name: %s\n", person_t.name);
	printf("Category: %d\n", person_t.category);
	printf("Height: %.2f\n", person_t.height);
	printf("Age: %d\n", person_t.age);
	printf("\n--- UNION content ---\n");
	printf("Name: %s (ASCCI)\n", person_u.name);
	printf("Category: %d\n", person_u.category);
	printf("Height: %.2f\n", person_u.height);
	printf("Age: %d\n\n", person_u.age);
	return 0;
}
