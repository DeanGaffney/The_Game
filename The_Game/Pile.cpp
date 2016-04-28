#include "Pile.h"

#include <iostream>

Pile::Pile(int start, int end, int number) :		//each pile has a start card,end card and a pile number (0-3).
startCard(start),
endCard(end),
m_Cards(new vector<Card>),
currentCard(start),									//currentCard on top of the pile.
pilePrecedence(0),
associatedCard(nullptr),							//used for the AI, links the card to the best matching pile.
pileNumber(number),
pileCompleted(false){
	if (start == 100)decreasingPile = true;			//tells me if a pile is decreasing or increasing depending on the starting card.
	m_Cards->reserve(m_MaxNumberOfCards);
	m_Cards->push_back(Card::Card(1));
	pileNumber = number;
}

Pile::Pile(){}

Pile::~Pile(){
	delete m_Cards;
	m_Cards = nullptr;
}

void Pile::addCard(Card card){	//add card to pile
	m_Cards->push_back(card);
}

void Pile::setEndCard(int value){	//set the end cad for the pile
	this->endCard = value;
}

void Pile::setStartCard(int value){	//set the starting card for the pile
	this->startCard = value;
}

bool Pile::checkPileCompletion(int value){		//see if a pile has been completed.
	return (value == endCard) ? true : false;
}

int Pile::getCurrentCard(){			//get the current card on top of the deck.
	return currentCard;
}

void Pile::setCurrentCard(int cardValue){
	this->currentCard = cardValue;
}

bool Pile::isDecreasingPile(){		//returns if the pile is a decreasing pile,false otherwise meaning its increasing.
	return decreasingPile;
}

int Pile::getPilePrecedence(){		//gives precedence to a pile and card for the AI to choose where to put a card.
	return this->pilePrecedence;
}

void Pile::setPrecedence(int precedence){
	pilePrecedence = precedence;
}

void Pile::setAssociatedCard(Card* card){	//links a card to the pile so AI can choose best card to place on the pile.
	associatedCard = card;
}

Card& Pile::getAssociatedCard(){
	return *associatedCard;
}

void Pile::setPileNumber(int number){		//sets the pile number.
	pileNumber = number;
}

int Pile::getPileNumber(){
	return pileNumber;
}