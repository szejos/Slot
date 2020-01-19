#pragma once
#include "Util.h"
#include "Reel.h"
class Game
{
	int const numberOfReels;
	int const numberOfPayLines;
	int credits = 500;
	std::map<std::vector<Symbol>, int> winLines;
	std::vector<std::unique_ptr<Reel>> reels;
	std::vector<std::map<symbolsEnum, int>> symbolsOnReels;


public:

	Game(int const& _numberOfReels, int const& _numberOfPayLines)
		: numberOfReels(_numberOfReels), numberOfPayLines(_numberOfPayLines)
	{
	}

	bool gameInit();
	void playTheGame();
	static void displayLine(int x, int y, std::vector<Symbol> vec, int color = 0);
	void displaySlot();
};

