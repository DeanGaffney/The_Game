#include "Pile.h"

#include <iostream>

Pile::Pile(int start,int end) : 
startCard(start),
endCard(end),
m_Cards(new vector<Card>),
currentCard(start),
pilePrecedence(0),
pileCompleted(false){
	if (start == 100)decreasingPile = true;
	m_Cards->reserve(m_MaxNumberOfCards);
	m_Cards->push_back(Card::Card(1));
}

Pile::Pile(){}

Pile::~Pile(){}

void Pile::addCard(Card card){
	m_Cards->push_back(card);
}

void Pile::setEndCard(int value){
	this->endCard = value;
}

void Pile::setStartCard(int value){
	this->startCard = value;
}

bool Pile::checkPileCompletion(int value){
	return (value == endCard) ? true : false;
}

int Pile::getCurrentCard(){
	return currentCard;
}

void Pile::setCurrentCard(int cardValue){
	this->currentCard = cardValue;
}

bool Pile::isDecreasingPile(){
	return decreasingPile;
}

int Pile::getPilePrecedence(){
	return this->pilePrecedence;
}

void Pile::setPrecedence(int precedence){
	pilePrecedence = precedence;
}