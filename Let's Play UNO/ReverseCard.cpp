/*
 * ReverseCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "ReverseCard.h"
#include "Player.h"
#include "ReverseCard.h"

ReverseCard::ReverseCard(Color color):Card(color,POINT_REVERSECARD) {
}

bool ReverseCard::operator^(const Card& t) const{
	if(typeid(t)==typeid(ReverseCard)){
		return true;
	}

	if (Card::operator ^(t)==true){
		return true;
	}
	return false;

}

void ReverseCard::castEffect(Player*& currentPlayer, CardPile& drawPile,CardPile& discardPile) {
	Player* prev=nullptr;
	Player* curr=currentPlayer;
	Player* next=nullptr;
	do {
		next=curr->nextPlayer;
		curr->nextPlayer=prev;
		prev=curr;
		curr=next;
	}while(curr!=currentPlayer);
	currentPlayer->nextPlayer=prev;          //reverse order
}

void ReverseCard::serialize(ostream& os) const {
	switch(color){
		case Color::red:
			os<<"Rr";
			break;
		case Color::blue:
			os<<"Br";
			break;
		case Color::green:
			os<<"Gr";
			break;
		case Color::yellow:
			os<<"Yr";
			break;
		case Color::meta:
			os<<"error";
			break;
}
}
