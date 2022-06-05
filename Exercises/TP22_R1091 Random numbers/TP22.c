#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main (void) {
	int a;
	srand(getpid());
	a = rand();
	printf("%d\n", (a % 12) - 5); // Devuelve nros entre -5 y 7
	return 0;
}
