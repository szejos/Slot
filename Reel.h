#pragma once
#include "Util.h"
#include "Symbol.h"

class Reel
{
	int numberOfSymbols;
	std::vector<Symbol> symbolsInReel; 

public:
	Reel() : numberOfSymbols(0)
	{}

	Reel(int const& _numberOfSymbols)
		: numberOfSymbols(_numberOfSymbols),
		  symbolsInReel(_numberOfSymbols)
	{}

	Reel(const Reel& other)
		: numberOfSymbols(other.numberOfSymbols),
		  symbolsInReel(other.symbolsInReel)
	{}

	Reel& operator=(const Reel& other)
	{
		return *this = Reel(other);
	}

	Reel(Reel&& other) noexcept
		: numberOfSymbols(std::exchange(other.numberOfSymbols, 0)),
		  symbolsInReel(std::move(other.symbolsInReel))
	{}

	~Reel()
	{}

	void shuffleSymbols();
	void insertSymbol(Symbol symbol, int numberTimes);
	Symbol getSymbol(int symbolPosition);
	std::array<Symbol, 6> randomSymbol();
	void printReel();
};

