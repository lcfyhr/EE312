//
// Created by vbhon and larsfyhr on 4/12/2020.
//

#include "card.h"
#include <string>

using namespace std;

//initial Card no condition
Card :: Card(){
	myRank = 1;
	mySuit = spades;
}

//initial card w conditions
Card :: Card(int rank, Suit s){
	myRank = rank;
	mySuit = s;
}

//return the suit as a string
string Card::suitString(Suit s) const {
	if (s == clubs){
		return "c";
	}
	if (s == diamonds){
		return "d";
	}
	if (s == hearts){
		return "h";
	}
	if (s == spades){
		return "s";
	}
}

//returns a string rank for the inputted int rank
string Card::rankString(int r) const {
	string ranks[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
	return ranks[r-1];
}

//returns string rank and suit
string Card::toString() const {
	return (rankString(myRank) + suitString(mySuit));
}

//checks if two cards have the same suit
bool Card::sameSuitAs(const Card &c) const {
	if (mySuit == c.mySuit){
		return true;
	}
	else{
		return false;
	}
}

//returns card rank
int Card::getRank() const {
	return myRank;
}

//checks if two cards are the same
bool Card::operator==(const Card &rhs) const {
	return ((mySuit == rhs.mySuit) && (myRank == rhs.myRank));
}

//checks if two cards are not the same
bool Card::operator!=(const Card &rhs) const {
	return ((mySuit != rhs.mySuit) || (myRank != rhs.myRank));
}


ostream& operator << (ostream& out, const Card& c){
	out << c.toString();
	return out;
}