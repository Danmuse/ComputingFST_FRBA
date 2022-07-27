#include <stdio.h>

typedef enum STATE{
    RUNNING = 49,	// 49 is '1' character on ASCCI table
    STOPPED = 50,	// 50 is '2' character on ASCCI table
    FAILED = 51,	// 51 is '3' character on ASCCI table
    HIBERNATING = 52	// 52 is '4' character on ASCCI table
} ST_MACHINE;

int main(void) {
    int input1;
    ST_MACHINE status;
    
    printf("Please provide integer in range [1-4]: ");
    input1 = getchar();
    status = input1;

    if (status == STOPPED) printf("Machine is stopped\n");
    else if (status == RUNNING) printf("Machine is running\n");
    else if (status == FAILED) printf("Machine is in failed state\n");
    else if (status == HIBERNATING) printf("Machine is hibernated\n");
    
    return 0;
}
