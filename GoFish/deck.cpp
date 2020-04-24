#include "deck.h"
#include "card.h"
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//init standard deck
Deck :: Deck() {
	myIndex = 0;
	for (int i = 0; i < SIZE; i++) {
		myCards[i] = Card((i%13 + 1), Card::Suit(i/13));
	}
}

//shuffles the cards in the deck
void Deck :: shuffle() {
	srand(time(NULL));
	for(int i = 0; i <= SIZE; i++) {
		int r1 = rand() % SIZE;
		int r2 = rand() % SIZE;
		Card tempCard = myCards[r1];
		myCards[r1] = myCards[r2];
		myCards[r2] = tempCard;
	}
}

//deals a card from the deck
Card Deck :: dealCard() {
	if (myIndex < SIZE) {
		Card tempcard = myCards[myIndex];
		myIndex++;
		return tempcard;
	}
}

//returns size of the deck
int Deck :: size() const {
	return SIZE - myIndex;
}