#include "DrawFourCard.h"
#include "Player.h"

	DrawFourCard::DrawFourCard():WildCard(){
	}

	void DrawFourCard::init(){
		color=Color::meta;
	}

	void DrawFourCard::castEffect(Player*& currentPlayer, CardPile& drawPile, CardPile& discardPile){
		Color select=currentPlayer->chooseColor();          //choose color
		color=select;                                       //fix color
		bool appeal=currentPlayer->getNextPlayer()->appealDrawFour();  //ask nextplayer appeal or not
		bool illegal=false;
		if(appeal==true){
			for(int i=0;i<currentPlayer->getSize();i++){
				if(currentPlayer->getCard(i)->operator^(*discardPile.getTopCard())==true){    	 //find the playable card
					illegal=true;																//only include color(override!!!)
				if(typeid(currentPlayer->getCard(i))==typeid(DrawFourCard))
					illegal=false;
				}
			}
			if(illegal==true){
				currentPlayer->drawCard(drawPile,discardPile,4);   //current player draw four cards
				return;
			}
			else {
				currentPlayer->nextPlayer->drawCard(drawPile,discardPile,6);    //next player draw 6 cards
				currentPlayer=currentPlayer->getNextPlayer();			//skip next player
				return;
			}
		}
		else{																	//not appeal
			currentPlayer->nextPlayer->drawCard(drawPile,discardPile,4);       //nextplayer draw 4 card
			currentPlayer=currentPlayer->getNextPlayer();                      //skip next player
			return;
			}
		}

	void DrawFourCard::serialize(ostream& os) const{
		switch(color){
			case Color::red:
				os<<"4R";
				break;
			case Color::blue:
				os<<"4B";
				break;
			case Color::green:
				os<<"4G";
				break;
			case Color::yellow:
				os<<"4Y";
				break;
			case Color::meta:
				os<<"+4";
				break;
	}
	}
