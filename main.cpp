#include <iostream>
#include "Game.h"

int main()
{
	// set some initial values
	int const reels = 3;

	std::map<int, std::map<symbolsEnum, int>> symbolsOnReels = {
		{0, std::map<symbolsEnum, int>{ {symbolsEnum::SEVEN, 1}, 
										{symbolsEnum::BAR, 3},
										{symbolsEnum::WATERMELON, 2},
										{symbolsEnum::BELL, 1},
										{symbolsEnum::PEACH, 7},
										{symbolsEnum::ORANGE, 5},
										{symbolsEnum::CHERRY, 2},
										{symbolsEnum::LEMON, 0},
										} 
		},
		{1, std::map<symbolsEnum, int>{ {symbolsEnum::SEVEN, 1},
										{symbolsEnum::BAR, 2},
										{symbolsEnum::WATERMELON, 2},
										{symbolsEnum::BELL, 5},
										{symbolsEnum::PEACH, 3},
										{symbolsEnum::ORANGE, 5},
										{symbolsEnum::CHERRY, 6},
										{symbolsEnum::LEMON, 0},
										}
		},
		{2, std::map<symbolsEnum, int>{ {symbolsEnum::SEVEN, 1},
										{symbolsEnum::BAR, 1},
										{symbolsEnum::WATERMELON, 2},
										{symbolsEnum::BELL, 8},
										{symbolsEnum::PEACH, 3},
										{symbolsEnum::ORANGE, 4},
										{symbolsEnum::CHERRY, 0},
										{symbolsEnum::LEMON, 4},
										}
		},
	};
	// create symbols
	std::map<symbolsEnum, Symbol> symbolsAvail = {
	{ symbolsEnum::SEVEN,	   Symbol(symbolsEnum::SEVEN, "777") },
	{ symbolsEnum::BAR,		   Symbol(symbolsEnum::BAR, "BAR") },
	{ symbolsEnum::WATERMELON, Symbol(symbolsEnum::WATERMELON, "WWW") },
	{ symbolsEnum::BELL,	   Symbol(symbolsEnum::BELL, "BEL") },
	{ symbolsEnum::PEACH,	   Symbol(symbolsEnum::PEACH, "PEA") },
	{ symbolsEnum::ORANGE,	   Symbol(symbolsEnum::ORANGE, "ORA") },
	{ symbolsEnum::CHERRY,	   Symbol(symbolsEnum::CHERRY, "CHE") },
	{ symbolsEnum::LEMON,	   Symbol(symbolsEnum::LEMON, "LEM") },
	};

	//create reels
	std::vector<Reel> reels;

	std::map <std::vector<Symbol>, int> payLines;


}