/*
 * DrawTwoCard.h
 *
 *  Created on: Feb 5, 2018
 *      Author: kevinw
 */

#ifndef DRAWTWOCARD_H_
#define DRAWTWOCARD_H_
#include<iostream>
#include <string>

#include "SkipCard.h"

using namespace std;

class DrawTwoCard:public SkipCard{
public:
	DrawTwoCard(Color color);

	bool operator^(const Card& t) const;

	void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);

	void serialize(ostream& os) const;

};
#endif /* DRAWTWOCARD_H_ */
