#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "AbstractPlayer.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class ComputerPlayer : public AbstractPlayer{
public:
	ComputerPlayer::ComputerPlayer(string name);
	ComputerPlayer::~ComputerPlayer();
	virtual void placeCard(vector<Card>& hand, vector<Pile>& piles);
	vector<Card> chooseCard(vector<Card>& hand, vector<Pile>& piles);
	void givePrecedence(vector<Card>& hand, vector<Pile>& piles);
	void evaluatePrecedence(int value1, int value2,Card &card, Pile &pile);
private:

};


#endif