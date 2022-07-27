#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define SIZE 30

typedef __UINT8_TYPE__ uint8_t;

char *my_strcat(char *, char **, int);
int scroll_letters(char *, char *);
void decrypt_letters(char *, char *, int);
void encrypt_numbers(char *, char *);
void decrypt_numbers(char *, char *);
int is_encrypt(char *);
