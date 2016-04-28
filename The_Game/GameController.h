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
	void init();													//sets up the classes and game objects at run time.
	bool isGameOver();												//checks if the game is over.
	void setGameOver();												//sets the game to game over state.
	void gameLoop();												//game loop where the game is played.
	void checkGameWin();											//see if the player has won the game.
	void removeCompletedPile();										//remove any piles from the game that are completed.
	void checkGameLose();											//see if the player has lost the game.
	void endOfGameMessage();										//display an end of game message
	void setPeopleKilled(int number);								//show score
	Deck* m_deck;													//pointer to deck.
	Pile* m_increasingPile;											//pointers to the game piles.
	Pile* m_increasingPile2;
	Pile* m_decreasingPile;
	Pile* m_decreasingPile2;
	AbstractPlayer* human;											//makes a human player
	AbstractPlayer* computer;										//make a computer player
	AbstractPlayer* currentPlayer;									//make a current player who is human or computer depending on the turn,saves me writing double the code.

private:
	int peopleKilled;
	int currentMove;
	bool m_gameOver;
	vector<Pile>* piles;
	const int numberOfPiles;
	bool playerWon;
	//TODO player
};
#endif