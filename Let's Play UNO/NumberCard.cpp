/*
 * NumberCard.cpp
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#include "NumberCard.h"

NumberCard::NumberCard(int point,Color color):Card(color,point){
}

bool NumberCard::operator^(const Card& t) const{
//	if (t.color == this->color)             //why color cant use here??
//		return true;
//	if (t.color == Color::meta)
//		return true;
	if (Card::operator ^(t)==true)
		return true;
	if(this->getPoint()==t.getPoint())
		return true;
	return false;
}

void NumberCard::castEffect(Player*& currentPlayer, CardPile &drawPile, CardPile &discardPile){
	return;  //no effect
}

void NumberCard::serialize(ostream& os) const{
	switch(color){
	case Color::red:
		os<<"R"<< getPoint();
		break;
	case Color::blue:
		os<<"B"<< getPoint();
		break;
	case Color::green:
		os<<"G"<< getPoint();
		break;
	case Color::yellow:
		os<<"Y"<< getPoint();
		break;
	case Color::meta:
		os<<"error";
		break;
	}
}
