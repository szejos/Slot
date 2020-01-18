#include "Reel.h"

void Reel::shuffleSymbols()
{
	std::shuffle(this->symbolsInReel.begin(),this->symbolsInReel.end(), 
				 std::default_random_engine(std::chrono::system_clock::now().time_since_epoch().count()));
}

void Reel::insertSymbol(Symbol symbol, int numberTimes)
{
	this->symbolsInReel.insert(this->symbolsInReel.end(), numberTimes, symbol);
}

Symbol Reel::getSymbol(int symbolPosition)
{
	return this->symbolsInReel.at(symbolPosition);
}

std::array<Symbol, 6> Reel::randomSymbol()
{
	int rand = std::rand() % this->symbolsInReel.size() + 1;
	int wrapper = (rand == 0) ? this->symbolsInReel.size() - 1 : rand;
	return array<Symbol, 6>(this->symbolsInReel.begin() + rand )
}

void Reel::printReel()
{
	std::cout << "Rozmiar: " << this->symbolsInReel.size() << " \n";
	for (const auto& symbol : this->symbolsInReel)
	{
		std::cout << symbol << "\n";
	}
}