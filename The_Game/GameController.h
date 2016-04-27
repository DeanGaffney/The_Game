#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Deck.h"
#include "Pile.h"
#include "AbstractPlayer.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

class GameController{
public:
	GameController();
	~GameController();
	void init();
	bool isGameOver();
	void setGameOver();
	void gameLoop();
	void checkGameWin();
	void removeCompletedPile();
	Deck* m_deck;
	Pile* m_increasingPile;
	Pile* m_increasingPile2;
	Pile* m_decreasingPile;
	Pile* m_decreasingPile2;
	AbstractPlayer* human;
	AbstractPlayer* computer;
	AbstractPlayer* currentPlayer;
private:
	int currentMove;
	bool m_gameOver;
	vector<Pile>* piles;
	const int numberOfPiles;
	bool playerWon;
	//TODO player
};
#endif