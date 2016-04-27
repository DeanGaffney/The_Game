#include "Deck.h"

#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

Deck::Deck(): 
m_MaxNumberOfCards(100),
m_Cards(new vector<Card>),
m_NumberOfCards(0){
	m_Cards->reserve(m_MaxNumberOfCards);
	populateDeck();
}
	

Deck::~Deck(){
	delete m_Cards;
	m_Cards = nullptr;
}

void Deck::addCard(Card cardToAdd){
	m_Cards->push_back(cardToAdd);	
}

//populate the deck full of cards
void Deck::populateDeck(){
	for (int i = 2; i < 100; ++i){
		Card card(i);
		addCard(card);
	}
}

void Deck::printDeck(){									//print out the deck
	for (int i = 0; i < m_Cards->size(); ++i)
		cout << m_Cards->at(i).getValue() << "\n";
}

void Deck::shuffleDeck(){
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(m_Cards->begin(), m_Cards->end());		//shuffle the deck.
}

void Deck::drawNumberOfCards(int numberToDraw){// method draws the number of cards desired and returns them as a list.
	for (int i = 0; i < numberToDraw; ++i){
		m_Cards->pop_back(); //remove them from the draw pile.
	}
}

//shows the amount of cards remaining in the deck.
int Deck::getRemainingCards(){
	return m_Cards->size();
}

vector<Card>& Deck::getDeck(){
	return *m_Cards;
}
