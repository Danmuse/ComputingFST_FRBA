#ifndef AUTOPART_LIST_H_
#define AUTOPART_LIST_H_

#include "utils.h"

#define MAX_SIZE_STR 100

typedef struct {
	int number;
	char name[MAX_SIZE_STR];
	int amount;
	float price;
} autopart_st;

typedef struct {
	autopart_st autopart;
	struct NODE_st* next;
} NODE_st;

typedef struct {
	NODE_st* header;
	int lenght;
} LIST_st;

NODE_st* CreateNode(autopart_st*);

void FreeNode(NODE_st*);

void InsertTop(LIST_st*, autopart_st*);

void InsertAfter(int, LIST_st*, autopart_st*);

autopart_st* GetPart(int, LIST_st*);

int ListLenght(LIST_st*);

bool EmptyStatus(LIST_st*);

#endif // AUTOPART_LIST_H_
