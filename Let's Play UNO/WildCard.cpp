/*
 * WildCard.cpp
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#include "WildCard.h"
#include "Player.h"

	WildCard::WildCard():Card(Color::meta,POINT_WILDCARD){
	}

	void WildCard::init(){
		color=Color::meta;
	}

	bool WildCard::operator^(const Card& t) const{
		return true;
	}

	void WildCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
		Color select=currentPlayer->chooseColor();    //ask currentplayer choose color
		color=select;                                //color fixed
	}

	void WildCard::serialize(ostream& os) const{
		switch(color){
			case Color::red:
				os<<"Rw";
				break;
			case Color::blue:
				os<<"Bw";
				break;
			case Color::green:
				os<<"Gw";
				break;
			case Color::yellow:
				os<<"Yw";
				break;                         //print Card info after it play
			case Color::meta:
				os<<"WC";
				break;

	}
}
