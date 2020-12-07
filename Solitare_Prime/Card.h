// Isaiah Guardado
// CECS 282-05
// Prog 1 - Solitare Prime
// September 17th 2019

#ifndef Card_h
#define Card_h


class Card {

private:
	char rank;
	char suit;

public:
	Card();
	Card(char r, char s);
	void setCard(char r, char s);
	int getValue();
	void showCard();

};

#endif
