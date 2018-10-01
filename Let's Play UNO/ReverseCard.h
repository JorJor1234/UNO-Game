/*
 * ReverseCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef REVERSECARD_H_
#define REVERSECARD_H_

#include<iostream>
#include<string>
#include<typeinfo>

#include "Card.h"

using namespace std;

class ReverseCard:public Card
{
public:
	ReverseCard(Color color);

	bool operator^(const Card& t) const;

	void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);

	void serialize(ostream& os) const;
};

#endif /* REVERSECARD_H_ */
