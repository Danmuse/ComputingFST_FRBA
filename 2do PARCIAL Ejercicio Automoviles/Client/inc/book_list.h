#ifndef BOOK_LIST_H_
#define BOOK_LIST_H_

#include "utils.h"

#define MAX_SIZE 50
#define ISBN_SIZE 13

typedef struct {
	char title[MAX_SIZE];
	char author[MAX_SIZE];
	char isbn[ISBN_SIZE];
} BOOK_st;

typedef struct {
	BOOK_st book;
	struct NODE_st* next;
} NODE_st;

typedef struct {
	NODE_st* header;
	int lenght;
} LIST_st;

NODE_st* CreateNode(BOOK_st*);

void FreeNode(NODE_st*);

void InsertTop(LIST_st*, BOOK_st*);

void InsertBottom(LIST_st*, BOOK_st*);

void InsertAfter(int, LIST_st*, BOOK_st*);

BOOK_st* GetBook(int, LIST_st*);

int ListLenght(LIST_st*);

bool EmptyStatus(LIST_st*);

void DeleteTop(LIST_st*);

void DeleteBottom(LIST_st*);

void DeleteElement(int, LIST_st*);

#endif // BOOK_LIST_H_
