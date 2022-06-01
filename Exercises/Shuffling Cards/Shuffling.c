#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <stdint.h>
// El único contenido importante de '<stdint.h>' es...

#ifdef _UINT8_TYPE_
typedef _UINT8_TYPE_ uint8_t;
#endif

struct card {
	// 'number' y 'naipe' van a ser punteros porque tendrán que ser
	// referenciados por un vector.
	const char *number;
	const char *naipe;
};

// Defino a "Card" como la estructura de una carta.
typedef struct card Card;

void assembleDeck(Card *const, const char *[], const char *[]);
void shuffle(Card *const);
void handOut(const Card *const);

int main(void) {
	Card deck[48];
	
	// Un vector es un array unidimencional, que utiliza un índice para
	// referenciar a cada uno de los elementos.
	// Cuando ya son inicializados, no es necesario indicarles el tamaño.
	// char vector[5]='\0' trunca la cadena de caracteres en la 5ta posición
	const char *number[] = {"Uno", "Dos", "Tres", "Cuatro", "Cinco", "Seis",
							"Siete", "Ocho", "Nueve", "Diez", "Once", "Doce"};
	const char *naipe[] = {"Oro", "Copa", "Basto", "Espada"};
	srand(time(NULL));
	assembleDeck(deck, number, naipe);
	shuffle(deck);
	handOut(deck);
	return 0;
}

void assembleDeck(Card *const ptrDeck, const char *ptrNumber[], const char *ptrNaipe[]) {
	int i;
	for(i = 0; i < 48; i++) {
		ptrDeck[i].number = ptrNumber[i % 12];
		ptrDeck[i].naipe = ptrNaipe[i / 12];
	}
}

void shuffle(Card *const ptrDeck) {
	int cant, i, j;
	Card aux_Card;
	
	for (i = 0; i < 48; i++) {
		j = rand() % 48;
		aux_Card = ptrDeck[i];
		ptrDeck[i] = ptrDeck[j];
		ptrDeck[j] = aux_Card;
	}
}

void handOut(const Card *const ptrDeck) {
	int i, j;
	printf("\nPrimer Jugador:\n");
	for (i = 0; i < 3; i++) printf("%s de %s\n", ptrDeck[i].number, ptrDeck[i].naipe);
	printf("\nSegundo Jugador:\n");
	for (j = 3; j < 6; j++) printf("%s de %s\n", ptrDeck[j].number, ptrDeck[j].naipe);
}
