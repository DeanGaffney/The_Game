#include "HumanPlayer.h"

HumanPlayer::HumanPlayer(string name) : AbstractPlayer(true){		//make human player from super constructor 
	this->name = name;
}

HumanPlayer::~HumanPlayer(){}

void HumanPlayer::placeCard(vector<Card>& hand, vector<Pile>& piles){
	//make place method here.
	int counter = 0;
	int cardNumber = 0;
	int pileNumber = 0;
	bool choosing = true;
	int quit;
	do{
		do{
			display(hand, piles);
			quit = getInput("CAN YOU PLAY AT LEAST 2 CARDS? ENTER 0 IF YOU CANT!! OR PRESS ANY OTHER NUMBER TO CONTINUE........");
			if (quit == 0)canPlayCard = false;
			if (!canPlayCard)break;									//break out if they cant play a card
			cardNumber = getInput("Please enter the card number you wish to pick.........") - 1;
			pileNumber = getInput("Please enter the pile number you wish to place the card on.........") - 1;
		} while (!checkValidCard(piles.at(pileNumber),hand.at(cardNumber)));//make sure its a vlid number for pile and card.
		
		if (!canPlayCard)break;										//break out if they cant play a card
		counter++;
		for (Pile &pile : piles){
			if (pileNumber == pile.getPileNumber()){
				pile.setCurrentCard(hand.at(cardNumber).getValue());			//places the card on the correct pile number
			}
		}			
		hand.erase(hand.begin() + cardNumber);									//erase the card from your hand
		display(hand, piles);													//display the updated game.
		if (counter > 1)doneChoosing(choosing);									//check and see if they want to place anymore cards.
	} while (choosing);
}

int HumanPlayer::getInput(string prompt){		//prompts human for input
	int value = 0;
	cout << prompt << endl;
	cin >> value;
	return value;
}

void HumanPlayer::doneChoosing(bool& choosing){	//done playing cards for this round.
	char answer;
	cout << "Do you want to place some more cards? (y/n)" << endl;
	cin >> answer;
	answer = tolower(answer);
	choosing = (answer == 'y') ? true : false;
}

bool HumanPlayer::checkValidCard(Pile pile, Card card){			//check if input is valid for both card chosen and pile chosen.
	if (pile.isDecreasingPile() && card.getValue() > pile.getCurrentCard()){
		cout << "Invalid move please put the correct card in the correct place." << endl;
		return false;
	}
	else if (!pile.isDecreasingPile() && card.getValue() < pile.getCurrentCard()){
		cout << "Invalid move please put the correct card in the correct place." << endl;
		return false;
	}
	else return true;
}
