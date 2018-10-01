/*
 * NumberCard.h
 *
 *  Created on: Jan 29, 2018
 *      Author: kevinw
 */

#ifndef NUMBERCARD_H_
#define NUMBERCARD_H_

#include <iostream>
#include <string>
#include "Card.h"

using namespace std;

class NumberCard:public Card{
public:
	NumberCard(int point,Color color);

	virtual bool operator^(const Card& t) const;

	void castEffect(Player*& currentPlayer, CardPile &drawPile, CardPile &discardPile);

	void serialize(ostream& os) const;


};

#endif /* NUMBERCARD_H_ */
