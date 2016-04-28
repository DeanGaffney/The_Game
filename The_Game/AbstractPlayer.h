#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H
#include "Card.h"
#include <vector>
#include "Deck.h"
#include <iostream>
#include "Pile.h"
#include <string>
/*
Abstract player class which sets out characteristics for the human and computer players.
The class has a pure virtual function which needs to be implemented by the dervied classes .
*/
#include <algorithm>

using namespace std;
class AbstractPlayer{				

public:
	AbstractPlayer(bool isHuman);												//allows me to know if human is player or not
	~AbstractPlayer();
	virtual void placeCard(vector<Card>& hand, vector<Pile>& piles) = 0;		//this method must be implemented by each player.
	virtual void setHuman(bool setting);										//make player a human
	virtual void seeHand();														//show player hand
	virtual void getMoreCards(Deck &deck,int cardsNeeded);						//pick up more cards from deck after turn.
	bool checkIsHuman();														//check if player is human.
	int checkNeededCards();														//check how many cards player needs to pick up 
	bool checkCanPlayCard();													//check and see if player can play any cards.
	void display(vector<Card> hand, vector<Pile> piles);						//display hand and game
	vector<Card>& getHand();													//return players hand.

protected:
	vector<Card> *hand;
	bool canPlayCard;		//checks to see if its possible to play a card depending on the players hand,false if cant be played
	bool isHuman;			//states if the player is human or computer.
	int maxCardsInHand;		//maximum cards in hand at any one time.
	string name;
};
#endif