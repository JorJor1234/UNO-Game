/*
 * DrawFourCard.h
 *
 *  Created on: Feb 6, 2018
 *      Author: kevinw
 */

#ifndef DRAWFOURCARD_H_
#define DRAWFOURCARD_H_
#include "WildCard.h"
#include<typeinfo>

using namespace std;

class DrawFourCard:public WildCard{
public:
	DrawFourCard();

	void init();

	void castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile);

	void serialize(ostream& os) const;

};

#endif /* DRAWFOURCARD_H_ */
