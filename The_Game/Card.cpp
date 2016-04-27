#include "Card.h"

Card::Card(int value){
	this->m_cardValue = value;
	this->cardPrecedence = 0;
}

Card::Card(){}

Card::~Card(){}

int Card::getValue(){
	return m_cardValue;
}

void Card::setValue(int value){
	this->m_cardValue = value;
}

int Card::getCardPrecedence(){
	return this->cardPrecedence;
}

void Card::setCardPrecedence(int precedence){
	this->cardPrecedence = precedence;
}


