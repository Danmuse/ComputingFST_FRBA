// "<stdio.h>" "<stdlib.h>" "<string.h>" "<stdbool.h>" "book.h" "BOOK_st" "LIST_st" "NODE_st" are included below...
#include "book_list.h"

NODE_st* CreateNode(BOOK_st* book) {
	NODE_st* node = (NODE_st*) malloc(sizeof(NODE_st));
	strncpy(node -> book.title, book -> title, MAX_SIZE);
	strncpy(node -> book.author, book -> author, MAX_SIZE);
	strncpy(node -> book.isbn, book -> isbn, ISBN_SIZE);
	node -> next = NULL;
	return node;
}

void FreeNode(NODE_st* node) {
	free(node);
}

void InsertTop(LIST_st* list, BOOK_st* book) {
	NODE_st* node = CreateNode(book);
	node -> next = list -> header;
	list -> header = node;
	list -> lenght++;
}

void InsertBottom(LIST_st* list, BOOK_st* book) {
	NODE_st* node = CreateNode(book);
	if (list -> header == NULL) list -> header = node;
	else {
		NODE_st* ptr = list -> header;
		while (ptr -> next) ptr = ptr -> next;
		ptr -> next = node;
	}
	list -> lenght++;
}

void InsertAfter(int n, LIST_st* list, BOOK_st* book) {
	NODE_st* node = CreateNode(book);
	if (list -> header == NULL) list -> header = node;
	else {
		NODE_st* ptr = list -> header;
		int position = 0;
		while (position < n && ptr -> next) {
			ptr = ptr -> next;
			position++;
		}
		node -> next = ptr -> next;
		ptr -> next = node;
	}
	list -> lenght++;
}

BOOK_st* GetBook(int n, LIST_st* list) {
	if (list -> header == NULL) return NULL;
	else {
		NODE_st* ptr = list -> header;
		int position = 0;
		while (list -> header && ptr -> next) {
			ptr = ptr -> next;
			position++;
		}
		return position != n ? NULL : &ptr -> book;
	}
}

int ListLenght(LIST_st* list) {
	return list -> lenght;
}

bool EmptyStatus(LIST_st* list) {
	return list -> header == NULL;
}

void DeleteTop(LIST_st* list) {
	if (list -> header) {
		NODE_st* deleted = list -> header;
		list -> header = list -> header -> next;
		FreeNode(deleted);
		list -> lenght--;
	}
}

void DeleteBottom(LIST_st* list) {
	if (list -> header) {
		if (list -> header -> next) {
			NODE_st* ptr = list -> header;
			// while (ptr -> next -> next) ptr = ptr -> next;
			while (ptr -> next) ptr = ptr -> next;
			NODE_st* deleted = ptr -> next;
			ptr -> next = NULL;
			FreeNode(deleted);
			list -> lenght--;
		} else {
			NODE_st* deleted = list -> header;
			list -> header = NULL;
			FreeNode(deleted);
			list -> lenght--;
		}
	}
}

void DeleteElement(int n, LIST_st* list) {
	if (list -> header) {
		if (n == 0) {
			NODE_st* deleted = list -> header;
			list -> header = list -> header -> next;
			FreeNode(deleted);
			list -> lenght--;
		} else if (n < list -> lenght) {
			NODE_st* ptr = list -> header;
			int position = 0;
			while (position < (n - 1)) {
				ptr = ptr -> next;
				position++;
			}
			NODE_st* deleted = ptr -> next;
			ptr -> next = deleted -> next;
			FreeNode(deleted);
			list -> lenght--;
		}
	}
}
