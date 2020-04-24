//
// Created by vbhon and larsfyhr on 4/13/2020.
//

#include "player.h"
#include "card.h"
#include <string>
#include <vector>

using namespace std;

//init standard player
Player :: Player() {
	myName = "";
}

//add card to player hand
void Player :: addCard(Card c) {
	myHand.push_back(c);
}

//books cards if two of same suit
void Player :: bookCards(Card c1, Card c2) {
	myBook.push_back(c1);
	removeCardFromHand(c1);
	myBook.push_back(c2);
	removeCardFromHand(c2);
}

//checks if there are two cards to book
bool Player :: checkHandForBook(Card &c1, Card &c2) {
	vector<Card>::const_iterator cloc1;
	vector<Card>::const_iterator cloc2;
	for(cloc1 = myHand.begin(); cloc1 != myHand.end(); cloc1++){
		for(cloc2 = cloc1+1; cloc2 != myHand.end(); cloc2++){
			if((*cloc1).getRank() == (*cloc2).getRank()){
				c1 = *cloc1;
				c2 = *cloc2;
				return true;
			}
		}
	}
	return false;
}

//checks for a certain card c in the hand
bool Player :: cardInHand(Card c) const {
	vector<Card>::const_iterator cloc;
	for(cloc = myHand.begin(); cloc != myHand.end(); cloc++){
		if(c == *cloc){
			return true;
		}
	}
	return false;
}

//checks if a hand has a certain card of same rank as c
bool Player :: rankInHand(Card c, Card &match) const {
	vector<Card>::const_iterator cloc;
	for(cloc = myHand.begin(); cloc != myHand.end(); cloc++){
		if(c.getRank() == (*cloc).getRank()){
			match = *cloc;
			return true;
		}
	}
	return false;
}

//reduces hand size
Card Player::chooseCardFromHand() const {
	return myHand[getHandSize() - 1];
}

//removes card c from the hand
Card Player :: removeCardFromHand(Card c) {
	Card tempCard;
	for(int i = 0; i < myHand.size(); i++){
		if(c == myHand[i]){
			tempCard = myHand[i];
			myHand.erase(myHand.begin()+i);
			return tempCard;
		}
	}
	return tempCard;
}

//shows the players hand
string Player :: showHand() const {
	vector<Card>::const_iterator cloc;
	string handlist;
	for (cloc = myHand.begin(); cloc < myHand.end(); cloc++) {
		handlist += (*cloc).toString() + "\n";
	}
	return handlist;
}

//retuns size of hand
int Player :: getHandSize() const {
	return myHand.size();
}

//shows what books player has
string Player :: showBooks() const {
	vector<Card>::const_iterator bloc;
	string booklist;
	for(bloc = myBook.begin(); bloc != myBook.end(); bloc += 2){
		booklist += (*bloc).toString() + " and " + (*(bloc+1)).toString() + "\n";
	}
	return booklist;
}

//returns how many books
int Player :: getBookSize() const {
	return myBook.size();
}