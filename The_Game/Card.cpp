#include "Card.h"

Card::Card(int value){			//each card has a value.
	this->m_cardValue = value;
	this->cardPrecedence = 0;
}

Card::Card(){}

Card::~Card(){}

int Card::getValue(){
	return m_cardValue;
}

void Card::setValue(int value){		//sets cards values
	this->m_cardValue = value;
}

int Card::getCardPrecedence(){		//gets card precedence
	return this->cardPrecedence;
}

void Card::setCardPrecedence(int precedence){		//sets precedence for card,this links a card a pile based on matching precedence to allow AI to choose best card to play.
	this->cardPrecedence = precedence;
}

void Card::setPileNumber(int number){
	pileNumber = number;
}

int Card::getPileNumber(){
	return pileNumber;
}


