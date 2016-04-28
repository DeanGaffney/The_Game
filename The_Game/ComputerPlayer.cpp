#include "ComputerPlayer.h"
ComputerPlayer::ComputerPlayer(string name):AbstractPlayer(false){
	this->name = name;
}

ComputerPlayer::~ComputerPlayer(){}

void ComputerPlayer::placeCard(vector<Card>& hand, vector<Pile>& piles){
	display(hand, piles);									//display hand before move
	vector<Card> cardsToPlay = chooseCard(hand, piles);		//gets the best cards from precedence evalutation.
	sort(cardsToPlay.begin(), cardsToPlay.end());			//sort the cards in descending order based on precedence. (Highest->Lowest).
	sort(piles.begin(), piles.end());						//sort piles based on their precedence(Highest->Lowest)
	int cardNumber = 0;
	int counter = 0;											//counter stops the computer playing(making a new array is too expensive for just two cards).
	for (Pile &pile : piles){
		if (counter < 2 && pile.getAssociatedCard().getCardPrecedence() > 3){	//go through the cards to play and set them to the current card on the pile,then remove from hand.
			pile.setCurrentCard(pile.getAssociatedCard().getValue());			//only allow computer to play 2 cards at a time.
			hand.erase(hand.begin() + cardNumber);
			cardNumber++;														
			counter++;
		}else continue;
	}
	display(hand, piles);
}	

vector<Card> ComputerPlayer::chooseCard(vector<Card>& hand, vector<Pile>& piles){
	vector<Card> cardsToPlay;
	givePrecedence(hand, piles);		//give cards precedence
	int max = 0;
	Card bestCard;
	for (Card card : hand){
		if (card.getCardPrecedence() >= 3){
			cardsToPlay.push_back(card);	//adds cards with a precedence of 3 or higher to the vector.
		}
		else continue;
	}
	if (cardsToPlay.size() < 2)canPlayCard = false;		//if we dont get more than 2 cards to play back we cant play anymore so we lose.
	return cardsToPlay;				//returns the best cards to play.
}

void ComputerPlayer::givePrecedence(vector<Card>& hand, vector<Pile>& piles){
	//go through the piles and observe the currentCard on the deck.
	//compare it to the cards in your hand.
	//pass reference of the objects to change their values during evaluation.
	for (Pile &pile : piles)
		for (Card &card : hand){
			if (pile.isDecreasingPile()){	//evaluate the difference differently depending if pile is increasing or decreasing.
				evaluatePrecedence(pile.getCurrentCard(),card.getValue(),card,pile);
			}
			else{
				evaluatePrecedence(card.getValue(), pile.getCurrentCard(), card, pile);		//swap the card and pile values for increasing piles.
			}
		}
}

/*this method checks the value of the card against the current card on the pile,
it then gives the pile and card matching precedence values to link them together.
This will end up with the best cards to play depedning on the highest precedence.
The method also links the card to the pointer Card object inside pile for association purposes.
*/
void ComputerPlayer::evaluatePrecedence(int value1,int value2,Card &card,Pile &pile){	//pass by reference to actually change the card and pile.
	
		//check for increasing possibilities
	int difference = value1 - value2;
		if (difference <= 5){
			if(card.getCardPrecedence() < 6)card.setCardPrecedence(6);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() < 6){
				pile.setPrecedence(6);
				pile.setAssociatedCard(&card);							//associate/link this card with this pile.
				card.setPileNumber(pile.getPileNumber());
			}
		}
		else if (difference > 5 && difference <= 10) {
			if (card.getCardPrecedence() < 5)card.setCardPrecedence(5);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() < 5){
				pile.setPrecedence(5);
				pile.setAssociatedCard(&card);
				card.setPileNumber(pile.getPileNumber());
			}
		}
		else if (difference > 10 && difference <= 15){
			if (card.getCardPrecedence() < 4)card.setCardPrecedence(4);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() < 4){
				pile.setPrecedence(4);
				pile.setAssociatedCard(&card);
				card.setPileNumber(pile.getPileNumber());
			}
		}
		else if (difference > 15 && difference <= 20){
			if (card.getCardPrecedence() < 3)card.setCardPrecedence(3);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() < 3){
				pile.setPrecedence(3);
				pile.setAssociatedCard(&card);
				card.setPileNumber(pile.getPileNumber());
			}
		}
		else if (difference > 20 && difference <= 30){
			if (card.getCardPrecedence() < 2)card.setCardPrecedence(2);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() < 2){
				pile.setPrecedence(2);
				pile.setAssociatedCard(&card);
				card.setPileNumber(pile.getPileNumber());
			}
		}
		else if (difference > 30 && difference <= 35){
			if (card.getCardPrecedence() < 1)card.setCardPrecedence(1);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() < 1){
				pile.setPrecedence(1);
				pile.setAssociatedCard(&card);
				card.setPileNumber(pile.getPileNumber());
			}
		}
		else{
			if (card.getCardPrecedence() <= 0)card.setCardPrecedence(0);	//these checks need to be done so we dont overwrite the precedence from previous checks.
			if (pile.getPilePrecedence() <= 0){
				pile.setPrecedence(0);
				pile.setAssociatedCard(&card);
				card.setPileNumber(pile.getPileNumber());
			}
		}
}