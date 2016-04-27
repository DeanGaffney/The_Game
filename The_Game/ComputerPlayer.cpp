#include "ComputerPlayer.h"
ComputerPlayer::ComputerPlayer(string name):AbstractPlayer(false){
	this->name = name;
}

ComputerPlayer::~ComputerPlayer(){}

void ComputerPlayer::placeCard(vector<Card>& hand, vector<Pile>& piles){
	vector<Card> cardsToPlay = chooseCard(hand, piles);		//gets the best cards from precedence evalutation.
	for (Pile pile : piles)
		for (Card card : cardsToPlay){
			if (card.getCardPrecedence() == pile.getPilePrecedence()){
				pile.setCurrentCard(card.getValue());
			}
		}
	display(hand, piles);
}	

vector<Card> ComputerPlayer::chooseCard(vector<Card> hand, vector<Pile> piles){
	vector<Card> cardsToPlay;
	givePrecedence(hand, piles);		//give cards precedence
	int max = 0;
	Card bestCard;
	for (Card card : hand){
		if (card.getCardPrecedence() >= 3){
			cardsToPlay.push_back(card);
		}
		else continue;
	}
	if (cardsToPlay.size() < 2)canPlayCard = false;		//if we dont get more than 2 cards to play back we cant play anymore so we lose.
	return cardsToPlay;				//returns the best card to play.
}

void ComputerPlayer::givePrecedence(vector<Card> hand, vector<Pile>piles){
	//go through the piles and observe the currentCard on the deck.
	//compare it to the cards in your hand.
	for (Pile pile : piles)
		for (Card card : hand){
			if (pile.isDecreasingPile()){
				evaluatePrecedence(pile.getCurrentCard(),card.getValue(),card,pile);
			}
			else{
				evaluatePrecedence(card.getValue(), pile.getCurrentCard(), card, pile);		//swap the card and pile values for increasing piles.
			}
		}
}

void ComputerPlayer::evaluatePrecedence(int value1,int value2,Card &card,Pile &pile){
	
		//check for increasing possibilities
	int difference = value1 - value2;
		if (difference <= 3){
			card.setCardPrecedence(6);
			pile.setPrecedence(6);
		}
		else if (difference > 3 && difference <= 6) {
			card.setCardPrecedence(5);
			pile.setPrecedence(5);
		}
		else if (difference > 6 && difference <= 9){
			card.setCardPrecedence(4);
			pile.setPrecedence(4);
		}
		else if (difference > 9 && difference <= 12){
			card.setCardPrecedence(3);
			pile.setPrecedence(3);
		}
		else if (difference > 12 && difference <= 15){
			card.setCardPrecedence(2);
			pile.setPrecedence(2);
		}
		else if (difference > 15 && difference <= 18){
			card.setCardPrecedence(1);
			pile.setPrecedence(1);
		}
}