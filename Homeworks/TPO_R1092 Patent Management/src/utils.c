#include "utils.h"

void checkAllocate(void *pointer) {
    if (!pointer) {
        perror("Critical error has occurred!");
        exit(EXIT_FAILURE);
    }
}