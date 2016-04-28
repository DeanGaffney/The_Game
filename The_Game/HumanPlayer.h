#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H
#include "AbstractPlayer.h"
#include <iostream>
#include<string>
using namespace std;

class HumanPlayer : public AbstractPlayer{
public:
	HumanPlayer(string name);
	~HumanPlayer();
	virtual void placeCard(vector<Card>& hand, vector<Pile>& piles);
	int getInput(string prompt);
	void doneChoosing(bool& choosing);
	void quit(string prompt);
	bool checkValidCard(Pile pile, Card card);
private:

};

#endif