#include <stdio.h>

void trade(int *, int *);

int main(void){
	int a = 5, b = 3;
	printf("a = %d b = %d\n", a, b);
	trade(&a, &b);
	printf("a = %d b = %d\n", a, b);
	return 0;
}

void trade(int *x, int *y){
	int z;
	z = *x;
	*x = *y;
	*y = z;
}
