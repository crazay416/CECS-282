// Isaiah Guardado
// CECS 282-05
// Prog 1 - Solitare Prime
// September 17th 2019

#ifndef Deck_h
#define Deck_h
#include "Card.h"

class Deck {
private:
	Card storage[52];
	int top = 0;
	char rank[13] = { 'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K' };
	char suit[4] = { 'S', 'D', 'H', 'C' };

public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int cardsLeft();
	void showDeck();

};

#endif
