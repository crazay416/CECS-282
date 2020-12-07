// Isaiah Guardado
// CECS 282-05
// Prog 1 - Solitare Prime
// September 17th 2019

#include "Card.h"
#include "Deck.h"
#include <iostream>
#include <math.h>

using namespace std;

bool getPrime(int number);
void solitarePrime(Deck deck);

int main() {

	Deck deck;
	bool playGame = true;
	int choose;

	while (playGame) {
		cout << "1. New Deck" << endl;
		cout << "2. Display Deck" << endl;
		cout << "3. Shuffle Deck" << endl;
		cout << "4. Play Solitare" << endl;
		cout << "5. Exit" << endl;

		cin >> choose;

		if (choose == 1) {
			deck.refreshDeck();
		}

		else if (choose == 2) {
			deck.showDeck();
		}

		else if (choose == 3) {
			deck.shuffle();
		}

		else if (choose == 4) {
			solitarePrime(deck);
			cout << endl;
		}

		else if (choose == 5) {
			playGame = false;
		}
	
	}

	cout << "Thank you for playing!" << endl;
}

void solitarePrime(Deck deck) {
	int total = 0;
	int totalPile = 0;
	int newSum = 0;
	
	while (deck.cardsLeft() > 0) {
		total = 0;
		Card card = deck.deal();
		card.showCard();
		total += card.getValue();

		while (!getPrime(total) && deck.cardsLeft() > 0) {
			card = deck.deal();
			card.showCard();
			total += card.getValue();
		}
		if (getPrime(total)) {
			cout << " Prime: " << total << endl;
			totalPile++;

		}

	}

	if (getPrime(total)) {
		cout << endl;
		cout << "Winner in " << totalPile << " piles!" << endl;
	}

	else {
		cout << endl;
		cout << "Loser total:" ;
		cout << total;
	}
	
}

bool getPrime(int number) {
	if (number == 1) {
		return false;
	}

	else if (number % 2 == 0) {
		return false;
	}

	else if (number == 2) {
		return true;
	}

	else {
		int current = 3;
		
		while (pow(current, 2) <= number) {
			if (number % current == 0) {
				return false;
			}
			else {
				current += 2;
			}
		}
	}
	return true;
}
