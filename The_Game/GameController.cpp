#include "GameController.h"
#include <algorithm>
#include <ctime>
#include <iostream>

using namespace std;

GameController::GameController() :				//set up all objects needed for game. (Computer plays first)
m_deck(new Deck()),
m_decreasingPile(new Pile(100, 2,0)),
m_decreasingPile2(new Pile(100, 2,1)),
m_increasingPile(new Pile(1, 99,2)),
m_increasingPile2(new Pile(1, 99,3)),
human(new HumanPlayer("Human")),
computer(new ComputerPlayer("Computer")),
currentPlayer(computer),						//currentplayer starts as the computer.
m_gameOver(false),
numberOfPiles(4),
currentMove(0),
playerWon(false),
piles(new vector<Pile>){
	piles->reserve(numberOfPiles);
	init();
}
	

GameController::~GameController(){		//delete and take care of all dynamic memory when destructor is called.
	delete m_deck;
	delete m_decreasingPile;
	delete m_decreasingPile2;
	delete m_increasingPile;
	delete m_decreasingPile2;
	delete human;
	delete computer;

	m_deck = nullptr;
	m_decreasingPile = nullptr;
	m_decreasingPile2 = nullptr;
	m_increasingPile = nullptr;
	m_decreasingPile2 = nullptr;
	human = nullptr;
	computer = nullptr;
}

//checks to see if the game is over
bool GameController::isGameOver(){
	return (this->m_gameOver) ? true : false;
}

//sets the game to a game over state.
void GameController::setGameOver(){
	this->m_gameOver = true;
}

//sets up the game
void GameController::init(){

	//sets up the deck for the game.
	cout << "Populating and shuffling Deck....................." << endl;
	m_deck->shuffleDeck();
	m_deck->printDeck();

	//set up piles and add them to piles vector.
	piles->push_back(*m_decreasingPile);
	piles->push_back(*m_decreasingPile2);
	piles->push_back(*m_increasingPile);
	piles->push_back(*m_increasingPile2);

	//set up people killed i.e score.(size of the deck)
	peopleKilled = m_deck->getDeck().size();
}

void GameController::gameLoop(){
	do{
		setPeopleKilled(m_deck->getDeck().size());
		cout << "PEOPLE WHO WILL DIE----> " << peopleKilled << endl;
		//give player cards
		currentPlayer->getMoreCards(*m_deck, currentPlayer->checkNeededCards());

		//player move OR computer move
		currentPlayer->placeCard(currentPlayer->getHand(), *piles);
		
		//check if the game is over before proceeding to next move
		checkGameWin();
		checkGameLose();

		//check for completed piles
		removeCompletedPile();

		//swap players
		currentPlayer = (currentPlayer->checkIsHuman()) ? computer : human;

	} while (!isGameOver());

	//call an end of game function here.
	endOfGameMessage();
}

void GameController::checkGameWin(){
	if (m_deck->getRemainingCards() == 0){ //if there are no more cards left in the deck the player has won
		m_gameOver = true;
		playerWon = true;
		return;
	}

	else if (piles->size() == 0){		//if theres no piles left i.e all completed by player game has to be over.
		m_gameOver = true;
		playerWon = true;
		return;
	}
	else return;
}

void GameController::checkGameLose(){			//checks to see if a player can play anymore cards,game over if they cant.
	if (!currentPlayer->checkCanPlayCard()){
		m_gameOver = true;
		playerWon = false;
	}
}

//end of game message depending on if player won or not.
void GameController::endOfGameMessage(){
	string win = "CONGRATULATIONS YOU WON!!NOBODY WILL DIE TONIGHT!!";
	string lose = "BETTER LUCK NEXT TIME! YOU KILLED " + to_string(peopleKilled);
	(playerWon) ? cout << win << endl : cout << lose << endl;
}

//removes piles from the vector 'piles' upon their completion by the player.
void GameController::removeCompletedPile(){
	int pileIndex = 0;
	for (Pile pile : *piles){	  //if no wins can be found go through the piles and remove any completed piles from the vector.
		if(pile.checkPileCompletion(pile.getCurrentCard()))piles->erase(piles->begin() + pileIndex);
		pileIndex++;
	}
}

void GameController::setPeopleKilled(int number){			//updates the people who will die/score every turn
	peopleKilled = number;
}
	