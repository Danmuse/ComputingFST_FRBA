#ifndef BOOK_H_
#define BOOK_H_

#include <stdio.h>
#define MAX_SIZE 50
#define ISBN_SIZE 13

typedef struct {
	char title[MAX_SIZE];
	char author[MAX_SIZE];
	char isbn[ISBN_SIZE];
} BOOK_st;

#endif // BOOK_H_
