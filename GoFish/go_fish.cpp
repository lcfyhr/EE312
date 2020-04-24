//
// Created by vbhon and larsfyhr on 4/13/2020.
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include "card.h"
#include "player.h"
#include "deck.h"

using namespace std;

void dealHand(Deck &d, Player &p, int handSize);

bool CheckThenBook(Player &p, Card &c);

void displayHandsandBooks(Player &p1, Player &p2);

void displayBookMsg(Player &p1, Player &p2, Card &c, ofstream &f);

void playerTurn(Player &active, Player &idle, Card &c, Card &m, Deck &d, ofstream &f, int turns);

int main(){

    ofstream file;
    file.open("gofish_results.txt");
    if(file.is_open()){
        cout << endl << "Succesfully opened file!" << endl;
        file << "~~~~~~~~~Welcome to the Go Fish game!~~~~~~~~~~" << endl;
    }

	Deck deck;
	deck.shuffle();
	Card tempCard;
	Card matchCard;
	int handSize = 7;
	int turns = 1;
	Player p1("Vishal");
	Player p2("Lars");
	dealHand(deck, p1, handSize);
	dealHand(deck, p2, handSize);

	file << p1.getName() << " and " << p2.getName() << " were both dealt " << handSize << " cards...\n" << endl;

	//displayHandsandBooks(p1, p2);
	file << "From the starting hands...\n" << endl;
	displayBookMsg(p1, p2, tempCard, file);
	cout << endl;

	//displayHandsandBooks(p1, p2);

	playerTurn(p1, p2, tempCard, matchCard, deck, file, turns);

	//displayHandsandBooks(p1, p2);

	file << p1.getName() << " had " << p1.getBookSize()/2 << " books, while "
	     << p2.getName() << " had " << p2.getBookSize()/2 << " books." << endl;

	if (p1.getBookSize() > p2.getBookSize()) {
		file << p1.getName() << " wins!" << endl;
	} else if (p2.getBookSize() > p1.getBookSize()){
		file << p2.getName() << " wins!" << endl;
	} else if (p1.getBookSize() == p2.getBookSize()) {
		file << p1.getName() << " and " << p2.getName() << " tied!" << endl;
	}

	file.close();
}

//deals hand to the player
void dealHand(Deck &d, Player &p, int handSize) {
	for (int i = 0; i < handSize; i++) {
		p.addCard(d.dealCard());
	}
}

//executes the playerTurns recursively
void playerTurn(Player &active, Player &idle, Card &c, Card &m, Deck &d, ofstream &f, int turns) {
	if (active.getHandSize() != 0) {
        f << "\nTurn " << turns << ": \n" << endl;
		c = active.chooseCardFromHand();
		f << active.getName() << " asks for " << c.rankString(c.getRank()) << endl;
		if (idle.rankInHand(c, m)) {
			active.addCard(idle.removeCardFromHand(m));
			f << idle.getName() << " gave " << active.getName() << " the " << c.rankString(c.getRank()) << "\n" << endl;
			displayBookMsg(active, idle, c, f);
			turns++;
			playerTurn(active, idle, c, m, d, f, turns);
		} else {
			f << idle.getName() << " says GO FISH!\n" << endl;
			f << active.getName() << " drew a card" << endl;
			active.addCard(d.dealCard());
			displayBookMsg(active, idle, c, f);
			turns++;
			playerTurn(idle, active, c, m, d, f, turns);
		}
	} else {
		if (d.size() != 0) {
            f << "\nTurn " << turns << ": \n" << endl;
			f << active.getName() << " has no cards, GO FISH!\n" << endl;
			f << active.getName() << " drew a card" << endl;
			active.addCard(d.dealCard());
			displayBookMsg(active, idle, c, f);
			turns++;
			playerTurn(idle, active, c, m, d, f, turns);
		} else {
			f << "\nDeck is empty and all cards are booked! GAME OVER!\n" << endl;
		}
	}
}

//checks if there is a possible book then books it
bool CheckThenBook(Player &p, Card &c) {
	Card c1, c2;
	if (p.checkHandForBook(c1, c2)) {
		p.bookCards(c1, c2);
		c = c1;
		return true;
	} else {
		return false;
	}
}

//outputs which player booked what cards
void displayBookMsg(Player &p1, Player &p2, Card &c, ofstream &f) {
	while (CheckThenBook(p1, c)) {
		f << p1.getName() << " booked the " << c.rankString(c.getRank()) << endl;
	}
	while (CheckThenBook(p2, c)) {
		f << p2.getName() << " booked the " << c.rankString(c.getRank()) << endl;
	}
}

//displays both players hands and books
void displayHandsandBooks(Player &p1, Player &p2) {
	cout << p1.getName() << "'s Hand:" << endl;
	cout << p1.showHand() << endl;
	cout << p1.getName() << "'s Books:" << endl;
	cout << p1.showBooks() << endl;
	cout << p2.getName() << "'s Hand:" << endl;
	cout << p2.showHand() << endl;
	cout << p2.getName() << "'s Books:" << endl;
	cout << p2.showBooks() << endl;
}