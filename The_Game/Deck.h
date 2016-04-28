#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"

class Deck{
public:
	Deck();
	~Deck();
	void addCard(Card& card);
	void populateDeck();
	void printDeck();
	void drawNumberOfCards(int numberToDraw);
	void shuffleDeck();
	int getRemainingCards();
	vector<Card>& getDeck();
	vector<Card>* m_Cards;

private:
	int m_NumberOfCards;
	int m_MaxNumberOfCards;
	Card m_card;
};
#endif