// "<stdio.h>" "<stdlib.h>" "<string.h>" "<stdbool.h>" "book.h" "BOOK_st" "LIST_st" "NODE_st" are included below...
#include "book_list.h"

void ClearBuffer(char*);

int main(void) {
	int option;
	LIST_st* list;
	BOOK_st* book;

	do {
		printf("\nIngrese el titulo del libro: ");
		ClearBuffer(book -> title);
		fgets(book -> title, MAX_SIZE, stdin);
        
		printf("Ingrese el autor del libro: ");
		ClearBuffer(book -> author);
		fgets(book -> author, MAX_SIZE, stdin);

		printf("Ingrese el ISBN del libro: ");
		ClearBuffer(book -> isbn);
		fgets(book -> isbn, ISBN_SIZE, stdin);

		InsertTop(list, book);
		printf("\n%s", book -> title);
		printf("\n%s", book -> author);
		printf("\n%s\n\n", book -> isbn);
		printf("Quiere ingresar otro libro? [0 = NO   1 = SI]: ");
		scanf("%d", &option);
	} while (option == 1);

	return 0;
}

void ClearBuffer(char *buffer) { if (buffer[strlen(buffer - 1)] != '\n') while (getchar() != '\n'); }
