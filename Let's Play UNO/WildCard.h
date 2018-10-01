/*
 * WildCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef WILDCARD_H_
#define WILDCARD_H_

#include<iostream>
#include<string>

#include "Card.h"

using namespace std;

class WildCard:public Card{
public:
	WildCard();

	void init();

	bool operator^(const Card& t) const;

	void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);

	void serialize(ostream& os) const;

};

#endif /* WILDCARD_H_ */
