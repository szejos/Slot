#include "Game.h"
#include "Util.h"
bool Game::gameInit()
{

	// set some initial values
	// how many of each symbol is on the reel
	symbolsOnReels = {
		std::map<symbolsEnum, int>{ {symbolsEnum::SEVEN, 1},
									{symbolsEnum::BAR, 3},
									{symbolsEnum::WATERMELON, 2},
									{symbolsEnum::BELL, 1},
									{symbolsEnum::PEACH, 7},
									{symbolsEnum::ORANGE, 5},
									{symbolsEnum::CHERRY, 2},
									{symbolsEnum::LEMON, 0},
								  },
		std::map<symbolsEnum, int>{ {symbolsEnum::SEVEN, 1},
									{symbolsEnum::BAR, 2},
									{symbolsEnum::WATERMELON, 2},
									{symbolsEnum::BELL, 5},
									{symbolsEnum::PEACH, 3},
									{symbolsEnum::ORANGE, 5},
									{symbolsEnum::CHERRY, 6},
									{symbolsEnum::LEMON, 0},
								  },
		std::map<symbolsEnum, int>{ {symbolsEnum::SEVEN, 1},
									{symbolsEnum::BAR, 1},
									{symbolsEnum::WATERMELON, 2},
									{symbolsEnum::BELL, 8},
									{symbolsEnum::PEACH, 3},
									{symbolsEnum::ORANGE, 4},
									{symbolsEnum::CHERRY, 0},
									{symbolsEnum::LEMON, 4},
								  }

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
	std::cout << " Tworzenie reelsow \n";
	//create reels
	for_each(this->symbolsOnReels.begin(), this->symbolsOnReels.end(), [&](std::map<symbolsEnum, int> reelMap)
	{
			int elementsOnReel = std::accumulate(reelMap.begin(), reelMap.end(), 0,
				[](int sumOfSymbols, std::pair<symbolsEnum, int> p) { return (sumOfSymbols + p.second); });

			std::unique_ptr<Reel> reel = std::make_unique<Reel>(elementsOnReel);
			std::cout << " Reel X: \n";
			for_each(reelMap.begin(), reelMap.end(), [&](std::pair<symbolsEnum, int> tempSymbolPair)
			{
					Symbol symbol(symbolsAvail[tempSymbolPair.first]);
					reel->insertSymbol(symbol, tempSymbolPair.second);
					std::cout << " Symbol: " << symbol << " \n";
			});

			reel->shuffleSymbols();
			this->reels.push_back(std::move(reel));
	});
	std::cout << " Po reelsow \n";
	reels.at(0)->printReel();

	std::map <std::vector<Symbol>, int> payLines;


	return true;

}