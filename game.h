#ifndef GAME_H
#define GAME_H

#include "graphics.h"


class Game
{
private:

	bool ChoiceNumber(sf::Event); //Ask the player number

	bool ChoiceBet(sf::Event); //Ask the player bet

	void SaveChoice(); //Save choice player

	void ChangeBetInPrice(sf::Event);

	void DiceRoll(); //Flip the coin
	void ComparePlayerChoice(); //Compare with player choice
	void ReplayOrNot();//Ask the player if they should play again

protected:
public:
	Game();

	void gameloop();
};

#endif // GAME_H
