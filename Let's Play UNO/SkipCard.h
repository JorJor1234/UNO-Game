/*
 * SkipCard.h
 *
 *  Created on: Feb 2, 2018
 *      Author: kevinw
 */

#ifndef SKIPCARD_H_
#define SKIPCARD_H_
#include <iostream>
#include <string>
#include"Card.h"

using namespace std;

class SkipCard:public Card{
public:
	SkipCard(Color);

	bool operator^(const Card& t) const;

	void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);

	void serialize(ostream& os) const;
};

#endif /* SKIPCARD_H_ */
