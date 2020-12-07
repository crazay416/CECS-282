// Isaiah Guardado
// CECS 282-05
// Prog 1 - Solitare Prime
// September 17th 2019

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

Deck::Deck() {

	refreshDeck();
}

	void Deck:: refreshDeck() {
		top = 0;
		int k = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				storage[k++].setCard(rank[j], suit[i]);
			}
		}
	}

	void Deck::showDeck() {
		top = 0;
		int k = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				storage[k++].showCard();
			}
			cout << endl;
		}
		cout << endl;
	}

	void Deck::shuffle() {
		srand(time(0));
		int i;

		for (i = 0; i < 52; i++) {
			Card temp = storage[i];
			int a = rand() % 52;
			storage[i] = storage[a];
			storage[a] = temp;
		}

	
	}

	Card Deck::deal() {
		return storage[top++];
	}


	int Deck::cardsLeft() {
		return 52 - top;
	}
