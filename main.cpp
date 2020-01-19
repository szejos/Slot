#include "Game.h"

int main()
{
	std::srand(std::time(0));


	Game Slot(3, 1);

	Slot.gameInit();
	Slot.playTheGame();

}