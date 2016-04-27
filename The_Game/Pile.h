#ifndef INCREASINGPILE_H
#define INCREASINGPILE_H
#include "Card.h"
#include <vector>

using namespace std;

class Pile{
public:
	Pile(int start,int end);
	Pile();
	~Pile();
	void addCard(Card card);
	bool checkPileCompletion(int cardValue);
	void setEndCard(int cardValue);
	void setStartCard(int cardValue);
	void setCurrentCard(int cardValue);
	int getCurrentCard();
	bool isDecreasingPile();
	int getPilePrecedence();
	void setPrecedence(int precedence);
private:
	vector<Card>* m_Cards;
	int m_MaxNumberOfCards = 100;
	int m_NumberOfcards;
	Card m_Card;
	int endCard;
	int startCard;
	bool pileCompleted;
	int currentCard;
	bool decreasingPile;			//lets me know if it's a decreasing or increasing pile
	int pilePrecedence;
};
#endif