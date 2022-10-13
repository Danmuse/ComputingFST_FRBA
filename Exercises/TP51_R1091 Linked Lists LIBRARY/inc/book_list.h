#ifndef BOOK_LIST_H_
#define BOOK_LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "book.h"

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
