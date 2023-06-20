// "<stdio.h>" "<stdlib.h>" "<string.h>" "<stdbool.h>" "autopart_st" "LIST_st" "NODE_st" are included below...
#include "autopart_list.h"

NODE_st* CreateNode(autopart_st* part) {
	NODE_st* node = (NODE_st*) malloc(sizeof(NODE_st));
	node -> autopart.number = part -> number;
	strncpy(node -> autopart.name, part -> name, MAX_SIZE_STR);
	node -> autopart.amount = part -> amount;
	node -> autopart.price = part -> price;
	node -> next = NULL;
	return node;
}

void FreeNode(NODE_st* node) {
	free(node);
}

void FreeList(LIST_st* list) {
	NODE_st *ptr = list -> header, *ptr_aux;
	while (ptr != NULL) {
		ptr_aux = ptr;
		ptr = ptr -> next;
		FreeNode(ptr_aux);
		list -> lenght--;
	}
}

void InsertTop(LIST_st* list, autopart_st* part) {
	NODE_st* node = CreateNode(part);
	node -> next = list -> header;
	list -> header = node;
	list -> lenght++;
}

void InsertAfter(int n, LIST_st* list, autopart_st* part) {
	NODE_st* node = CreateNode(part);
	if (EmptyStatus(list)) list -> header = node;
	else {
		int position = 0;
		NODE_st* ptr = list -> header;
		while (position < n && ptr -> next) {
			ptr = ptr -> next;
			position++;
		}
		node -> next = ptr -> next;
		ptr -> next = node;
	}
	list -> lenght++;
}

autopart_st* GetPart(int partnumber, LIST_st* list) {
	if (EmptyStatus(list)) return NULL;
	else {
		int position = 0;
		NODE_st* ptr = list -> header;
		while (list -> header && ptr -> next) {
			ptr = ptr -> next;
			position++;
		}
		return position != partnumber ? NULL : &ptr -> autopart;
	}
}

int Order(int partnumber, int discount, LIST_st* list) {
	// The product doesn't exist
	if (EmptyStatus(list)) return -1;
	else {
		int position = 0;
		NODE_st* ptr = list -> header;
		while (list -> header && ptr -> next) {
			ptr = ptr -> next;
			position++;
		}
		if (position == partnumber) {
			// The order exceeds the quantity available 
			if (*(&ptr -> autopart.amount) - discount <= 0) return 0;
			else {
				*(&ptr -> autopart.amount) -= discount;
				// The quantity available after the order is...
				return *(&ptr -> autopart.amount);
			}
		// The part number entered doesn't exist
		} else return -1;
	}
}

void showList(LIST_st list) {
	NODE_st* ptr = list.header;
	// fprintf(stdout, "\nHeader Pointer: %p", ptr);
	while (ptr != NULL) {
		fprintf(stdout, "\nP/N: %d", ptr -> autopart.number);
		fprintf(stdout, "\nPart Name: %s", ptr -> autopart.name);
		fprintf(stdout, "\nPart Quantity: %d", ptr -> autopart.amount);
		fprintf(stdout, "\nPart Price: %.2f\n", ptr -> autopart.price);
		ptr = ptr -> next;
		// fprintf(stdout, "\nNext Pointer: %p\n", ptr);
	}
}

int ListLenght(LIST_st* list) {
	return list -> lenght;
}

bool EmptyStatus(LIST_st* list) {
	return list -> header == NULL;
}
