#ifndef ABSTRACTPLAYER_H
#define ABSTRACTPLAYER_H
#include "Card.h"
#include <vector>
#include "Deck.h"
#include <iostream>
#include "Pile.h"
#include <string>
#include <algorithm>

using namespace std;
class AbstractPlayer{

public:
	AbstractPlayer(bool isHuman);
	~AbstractPlayer();
	virtual void placeCard(vector<Card>& hand, vector<Pile>& piles) = 0;		//this method must be implemented by each player.
	virtual void setHuman(bool setting);
	virtual void seeHand();
	virtual void getMoreCards(Deck &deck,int cardsNeeded);
	bool checkIsHuman();
	int checkNeededCards();
	void display(vector<Card> hand, vector<Pile> piles);
	vector<Card>& getHand();

protected:
	vector<Card> *hand;
	bool canPlayCard;		//checks to see if its possible to play a card depending on the players hand,false if cant be played
	bool isHuman;			//states if the player is human or computer.
	int maxCardsInHand;		//maximum cards in hand at any one time.
	string name;
};
#endif