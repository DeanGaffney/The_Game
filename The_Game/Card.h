#ifndef CARD_H
#define CARD_H
#include<ostream>
using namespace std;

class Card
{
public:
	Card(int value);
	Card();
	~Card();
	int getValue();
	void setValue(int value);
	int getCardPrecedence();
	void setCardPrecedence(int precedence);
	bool operator<(const Card& other)const{
		if (cardPrecedence == other.cardPrecedence)
		{
			return cardPrecedence < other.cardPrecedence;
		}

		return cardPrecedence < other.cardPrecedence;
	}

	friend ostream& operator<<(ostream& stream, const Card& card){
		stream << "Card value: " << card.m_cardValue << " Card Precedence: " << card.cardPrecedence << endl;
		return stream;
	}
		

private:
	int m_cardValue;
	int cardPrecedence;
	int maxPrecedence = 6;
};

#endif 
