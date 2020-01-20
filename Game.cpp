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

	return true;
}
void Game::displayLine(int x, int y, std::vector<Symbol> vec, int color)
{
	int stepX = 10;
	int stepY = 6;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

	for (int i = 0; i <= vec.size() - 3; ++i)
	{
		for (int k = 0; k < 3; ++k)
		{
			COORD startXY = { x, y + k*stepY };
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), startXY);
			std::cout << vec.at(i+k);
		}
		Sleep(300);
	}
}

void Game::playTheGame()
{

	char charPick = 1;
	bool mainLoop = true;
	while (mainLoop)
	{	
		std::vector<std::vector<Symbol>> results;
		for(auto&& reel: this->reels)
		{
			results.push_back(reel->randomSymbol());
		}

		std::vector<Symbol> line{ results.at(0).at(4), 
								  results.at(1).at(4), 
								  results.at(2).at(4)};

		auto win = winLines.find(line);

		system("cls");
		this->displaySlot();

		int i = 0;
		for (auto vec : results)
		{
			this->displayLine(23 + (i++ * 10), 11, vec, 10);
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		COORD startXY = { 25, 29 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), startXY);
		if (win != winLines.end())
		{
			std::cout << " Won " << win->second * (charPick - '0') << " credit \n";
			this->credits += win->second * (charPick - '0');
		}
		else
		{
			std::cout << " --------------- \n";

		}

		startXY = { 0, 40 };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), startXY);
		do
		{
			charPick = _getch();
		} while (charPick != 'e' && charPick != '1' && charPick != '2' && charPick != '3');

		this->credits -= charPick - '0';
		if (charPick == 'e' || this->credits < 1)
		{
			mainLoop = false;
		}
	}

}

void Game::displaySlot()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
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
	std::cout << "       payline - ||*|       |-|       |-|       |*|| ||\n";
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
	std::cout << "                 |   |                         |   |\n";
	std::cout << "                _|    \\_______________________/    |_\n";
	std::cout << "               (_____________________________________)\n";

	std::cout << "\n                Credits: " << this->credits << " \n";
	std::cout << "                Press: 1 - play 1xcredit\n";
	std::cout << "                       2 - play 2xcredit\n";
	std::cout << "                       3 - play 3xcredit\n";
}