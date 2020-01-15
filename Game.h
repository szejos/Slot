#pragma once
#include <map>
#include "Reel.h"
class Game
{
	int const numberOfReels;
	int const numberOfPayLines;
	std::map <std::vector<Symbol>, int> payLines;

public:
	Game(int const& _numberOfReels, int const& _numberOfPayLines, 
		 std::map <std::vector<Symbol>, int>& _payLines)
		: numberOfReels(_numberOfReels), numberOfPayLines(_numberOfPayLines),
		  payLines(std::move(_payLines))
	{}
};

