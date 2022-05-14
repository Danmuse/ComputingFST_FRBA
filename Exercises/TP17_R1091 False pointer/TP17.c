#include <stdio.h>
int sum(int);

int main (void){
        int x;
        printf("\nIngrese un numero:\t");
        scanf("%d", &x);
        x = sum(x);
        printf("Memoria \"x\" %p\t", &x);
        printf("x = %d\n", x);
        return 0;
}

int sum(int z) {
        z += 3;
        printf("\nMemoria \"z\" %p\t", &z);
        printf("x = %d\n", z);
        return z;
}

