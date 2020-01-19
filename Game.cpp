#include "Game.h"
#include "Util.h"


bool Game::gameInit()
{
	// set some initial values
	// how many of each symbol is on the reel
	this->symbolsOnReels = {
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

	//create reels and shuffle symbols
	for_each(this->symbolsOnReels.begin(), this->symbolsOnReels.end(), [&](std::map<symbolsEnum, int> reelMap)
	{
			int elementsOnReel = std::accumulate(reelMap.begin(), reelMap.end(), 0,
				[](int sumOfSymbols, std::pair<symbolsEnum, int> p) { return (sumOfSymbols + p.second); });

			std::unique_ptr<Reel> reel = std::make_unique<Reel>();
			for_each(reelMap.begin(), reelMap.end(), [&](std::pair<symbolsEnum, int> tempSymbolPair)
			{
					Symbol symbol(symbolsAvail[tempSymbolPair.first]);
					reel->insertSymbol(std::move(symbol), tempSymbolPair.second);
			});

			reel->shuffleSymbols();
			this->reels.push_back(std::move(reel));
	});


	//reels.at(0)->printReel();
	//reels.at(1)->printReel();
	//reels.at(2)->printReel();

	// symbols combination as key in map / credits paid
	this->winLines = 
	{
		{std::vector<Symbol>(3, symbolsAvail[symbolsEnum::SEVEN]), 
							 200},
		{std::vector<Symbol>(3, symbolsAvail[symbolsEnum::BAR]),
							 100},
		{std::vector<Symbol>(3, symbolsAvail[symbolsEnum::WATERMELON]),
							 100},
		{std::vector<Symbol>(3, symbolsAvail[symbolsEnum::BELL]),
							 18},
		{std::vector<Symbol>(3, symbolsAvail[symbolsEnum::PEACH]),
							 14},
		{std::vector<Symbol>(3, symbolsAvail[symbolsEnum::ORANGE]),
							 10},
		{std::vector<Symbol>(2, symbolsAvail[symbolsEnum::CHERRY]),
							 5},
		{std::vector<Symbol>(1, symbolsAvail[symbolsEnum::CHERRY]),
							 2},
		{std::vector<Symbol>{symbolsAvail[symbolsEnum::WATERMELON], symbolsAvail[symbolsEnum::WATERMELON], 
							 symbolsAvail[symbolsEnum::BAR]},
							 100},
		{std::vector<Symbol>{symbolsAvail[symbolsEnum::BELL], symbolsAvail[symbolsEnum::BELL], 
							 symbolsAvail[symbolsEnum::BAR]},
							 18},
		{std::vector<Symbol>{symbolsAvail[symbolsEnum::PEACH], symbolsAvail[symbolsEnum::PEACH], 
							 symbolsAvail[symbolsEnum::BAR]},
							 14},
		{std::vector<Symbol>{symbolsAvail[symbolsEnum::ORANGE], symbolsAvail[symbolsEnum::ORANGE],
							 symbolsAvail[symbolsEnum::BAR]},
							 10}
	};

	//std::vector<Symbol> d(3, symbolsAvail[symbolsEnum::SEVEN]);

	
	//std::cout << " kredyty: " << winLines.find(d)->second;
	return true;
}
void Game::setConsole(int x, int y, int color)
{
	COORD xy = { x, y };
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void Game::playTheGame()
{

	int choicePick;
	bool mainLoop = true;
	int k = 1000000;
	int count = 0;
	//while (mainLoop)
	{	
		std::vector<std::vector<Symbol>> results;
		for(auto&& reel: this->reels)
		{
				results.push_back(reel->randomSymbol());
		}


		std::vector<Symbol> line{ results.at(0).at(1), 
								  results.at(1).at(1), 
								  results.at(2).at(1)};



		auto win = winLines.find(line);

		//con << std::string(" Wylosowana linia: ");// << line.at(0) << "-" << line.at(1) << "-" << line.at(2) << " \n";
		if (win != winLines.end())
		{
			//std::cout << " Wylosowana linia: " << line.at(0) << "-" << line.at(1) << "-" << line.at(2) << " \n";
			//std::cout << " Wygrana: linia / kredyty " <<  win->second << " \n";

		}
		system("cls");
		this->displaySlot();
		Game::setConsole(23, 11, 10);
		std::cout << "777";
		Game::setConsole(33, 11, 10);
		std::cout << "777";
		Game::setConsole(43, 11, 10);
		std::cout << "777";
		Game::setConsole(23, 17, 10);
		std::cout << "777";
		Game::setConsole(33, 17, 10);
		std::cout << "777";
		Game::setConsole(43, 17, 10);
		std::cout << "777";
		Game::setConsole(23, 23, 10);
		std::cout << "777";
		Game::setConsole(33, 23, 10);
		std::cout << "777";
		Game::setConsole(43, 23, 10);
		std::cout << "777";
		getchar();
	}
	//std::cout << "Wygranych: " << count;
	//std::cout << "Choose ";
	//std::cin >> choicePick;

}

void Game::displaySlot()
{
	std::cout << "                              .-------.\n";
	std::cout << "                              |Jackpot|\n";
	std::cout << "                  ____________|_______|____________\n";
	std::cout << "                 |  __    __    ___  _____   __    |  \n";
	std::cout << "                 | / _\\  / /   /___\\/__   \\ / _\\   | \n";
	std::cout << "                 | \\ \\  / /   //  //  / /\\ \\\\ \\  25|  \n";
	std::cout << "                 | _\\ \\/ /___/ \\_//  / /  \\/_\\ \\ []| \n";
	std::cout << "                 | \\__/\\____/\\___/   \\/     \\__/ []|\n";
	std::cout << "                 |===_______===_______===_______===|\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|       |*|       |*|       |*|| __\n";
	std::cout << "                 ||*|_______|*|_______|*|_______|*||(__)\n";
	std::cout << "                 |===_______===_______===_______===| ||\n";
	std::cout << "                 ||*|       |*|       |*|       |*|| ||\n";
	std::cout << "                 ||*|       |*|       |*|       |*|| ||\n";
	std::cout << "                 ||*|       |*|       |*|       |*|| ||\n";
	std::cout << "                 ||*|       |*|       |*|       |*|| ||\n";
	std::cout << "                 ||*|_______|*|_______|*|_______|*||_//\n";
	std::cout << "                 |===_______===_______===_______===|_/\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|       |*|       |*|       |*||\n";
	std::cout << "                 ||*|_______|*|_______|*|_______|*||\n";
	std::cout << "                 |lc=___________________________===|\n";
	std::cout << "                 |  /___________________________\\  |\n";
	std::cout << "                 |   |                         |   |\n";
	std::cout << "                _|    \\_______________________/    |_\n";
	std::cout << "               (_____________________________________)\n";
}