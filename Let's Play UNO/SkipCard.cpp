/*
 * SkipCard.cpp
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#include "SkipCard.h"
#include "Player.h"

SkipCard::SkipCard(Color color):Card(color,POINT_SKIPCARD){
}

bool SkipCard::operator^(const Card& t) const{
	if(typeid(t)==typeid(SkipCard))
		return true;
	if (Card::operator ^(t)==true)
		return true;
	return false;

}

void SkipCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
	currentPlayer=currentPlayer->getNextPlayer(); //skip the next player
}

void SkipCard::serialize(ostream& os) const{
	switch(color){
		case Color::red:
			os<<"Rs";
			break;
		case Color::blue:
			os<<"Bs";
			break;
		case Color::green:
			os<<"Gs";
			break;
		case Color::yellow:
			os<<"Ys";
			break;
		case Color::meta:
			os<<"error";
			break;
}
}
