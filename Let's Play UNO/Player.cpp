/*
 * Player.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "Player.h"
#include<typeinfo>

ostream& operator<<(ostream& os, const Player& h) {
	os << h.name << ":";
	for (int i = 0; i < h.getSize(); i++) {
		os << *h.getCard(i) << " ";
	}
	return os;
}

Player::Player(string name, Player* previous){
	this->name=name;
	if(previous!=nullptr){
		if(previous->nextPlayer==nullptr){
			this->nextPlayer=previous;
			previous->nextPlayer=this;
		}
		else{
			this->nextPlayer=previous->nextPlayer;
			previous->nextPlayer=this;
		}
	}else
		this->nextPlayer=nullptr;

}

void Player::drawCard(CardPile& drawPile, CardPile& discardPile, int number_of_cards){
	if(drawPile.getSize()>number_of_cards){                     //drawPile have enough card
		for(int i=0;i<number_of_cards;i++){
		Card* addcard=drawPile.removeTopCard();
		this->operator +=(addcard);
		}
	}
	else{															//drawPilehaven't enough card
		int remainCard=number_of_cards-drawPile.getSize();
		for(int i=0;i<drawPile.getSize();i++){
			Card* addcard=drawPile.removeTopCard();
			this->operator +=(addcard);                            //first draw all card from drawPile
		}
		for(int i=0;i<discardPile.getSize()-2;i++){
			Card* addcard=discardPile.removeCard(i);           //place the card of discardPile back to drawPile
			addcard->init();
			drawPile.operator +=(addcard);
		}
		drawPile.shuffle(); 							//drawPile shuffle
		int numAddCard=0;
		if(drawPile.getSize()>remainCard)                    //Now drawPile have enough card
			numAddCard=remainCard;
		else if(drawPile.getSize()<=remainCard)				//Now drawPile haven't enough card
			numAddCard=drawPile.getSize();

		for(int i=0;i<numAddCard;i++){
			Card* addcard=drawPile.removeTopCard();
			this->operator +=(addcard);                     //add remaining card to player
		}
	}
}



Card* Player::playCardAfter(const Card* topCard, int index){
		if(index>=this->getSize()|| index < 0)   //index is out of bound
			return nullptr;
		else if(this->getCard(index)->operator^(*topCard)==true){    //valid input
			if(this->getSize()==1 && (typeid(*this->getCard(index)) != typeid(NumberCard))){      //the last card is not a number card!!
				return nullptr;}
			Card* playCard=this->removeCard(index);
			return playCard;
		}
		else											//invalid input
			return nullptr;
}

int Player::getScore() const{
	int score=0;
	for(int i=0;i<this->CardPile::getSize();i++)
		score += this->getCard(i)->getPoint();
	return score;
}
