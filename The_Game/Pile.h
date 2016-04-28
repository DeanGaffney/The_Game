#ifndef INCREASINGPILE_H
#define INCREASINGPILE_H
#include "Card.h"
#include <vector>

using namespace std;			//see Pile.cpp for comments and details!

class Pile{
public:
	Pile(int start,int end,int number);
	Pile();
	~Pile();
	void addCard(Card card);
	bool checkPileCompletion(int cardValue);
	void setEndCard(int cardValue);
	void setStartCard(int cardValue);
	void setCurrentCard(int cardValue);
	int getCurrentCard();
	int getPileNumber();
	void setPileNumber(int number);
	bool isDecreasingPile();
	int getPilePrecedence();
	void setPrecedence(int precedence);
	void setAssociatedCard(Card* card);
	Card& getAssociatedCard();
	bool operator<(const Pile& other)const{		
		if (associatedCard->getCardPrecedence() == other.associatedCard->getCardPrecedence())
		{
			return associatedCard->getCardPrecedence() > other.associatedCard->getCardPrecedence();
		}

		return associatedCard->getCardPrecedence() > other.associatedCard->getCardPrecedence();
	}
private:
	int pileNumber;
	vector<Card>* m_Cards;
	int m_MaxNumberOfCards = 100;
	int m_NumberOfcards;
	Card m_Card;
	Card* associatedCard;			//used for the computer player to associate the best choice card with the pile.
	int endCard;
	int startCard;
	bool pileCompleted;
	int currentCard;
	bool decreasingPile;			//lets me know if it's a decreasing or increasing pile
	int pilePrecedence;
};
#endif