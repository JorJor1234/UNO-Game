/*
 * DrawTwoCard.cpp
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#include "DrawTwoCard.h"
#include "Player.h"

DrawTwoCard::DrawTwoCard(Color color):SkipCard(color) {
}

bool DrawTwoCard::operator^(const Card& t) const{
	if(typeid(t)==typeid(DrawTwoCard)){
		return true;}
	if (Card::operator ^(t)==true){
		return true;}
	return false;

}

void DrawTwoCard::castEffect(Player*& currentPlayer, CardPile& drawPile,CardPile& discardPile) {
	currentPlayer->getNextPlayer()->drawCard(drawPile,discardPile,2);    //next player draw two card
	currentPlayer=currentPlayer->getNextPlayer();                       //skip the next player
}

void DrawTwoCard::serialize(ostream& os) const {
	switch(color){
			case Color::red:
				os<<"R+";
				break;
			case Color::blue:
				os<<"B+";
				break;
			case Color::green:
				os<<"G+";
				break;
			case Color::yellow:
				os<<"Y+";
				break;
			case Color::meta:
				os<<"error";
				break;
}
}
