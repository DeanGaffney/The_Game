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
	do{
		do{
			display(hand, piles);
			cardNumber = getInput("Please enter the card number you wish to pick.........") - 1;
			pileNumber = getInput("Please enter the pile number you wish to place the card on.........") - 1;
		} while (!checkValidCard(piles.at(pileNumber),hand.at(cardNumber)));
		
		counter++;
		piles.at(pileNumber).setCurrentCard(hand.at(cardNumber).getValue());	//set the new pile cad to the card that was picked.
		hand.erase(hand.begin() + cardNumber);
		display(hand, piles);
		if (counter > 1)doneChoosing(choosing);									//check and see if they want to place anymore cards.
	} while (choosing);
}

int HumanPlayer::getInput(string prompt){
	int value = 0;
	cout << prompt << endl;
	cin >> value;
	return value;
}

void HumanPlayer::doneChoosing(bool& choosing){
	char answer;
	cout << "Do you want to place some more cards? (y/n)" << endl;
	cin >> answer;
	answer = tolower(answer);
	choosing = (answer == 'y') ? true : false;
}

bool HumanPlayer::checkValidCard(Pile pile, Card card){
	if (pile.isDecreasingPile() && card.getValue() > pile.getCurrentCard()){
		cout << "Invalid move please put the correct card in the correct place." << endl;
		return false;
	}
	else if (!pile.isDecreasingPile() && card.getValue() < pile.getCurrentCard()){
		cout << "Invalid move please put the correct card in the correct place." << endl;
		return false;
	}
}
