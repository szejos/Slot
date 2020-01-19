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

std::vector<Symbol> Reel::randomSymbol()
{
	int rand = std::rand() % this->symbolsInReel.size() + 1;
	std::vector<Symbol> ret;
	int i = 0;
	for(auto it = this->symbolsInReel.begin() + rand; i < 6; ++it)
	{
		//wraping
		if (it == this->symbolsInReel.end())
			it = this->symbolsInReel.begin();

		ret.push_back(*it);
		++i;
	}
	return ret;
}

void Reel::printReel()
{
	std::cout << "Rozmiar: " << this->symbolsInReel.size() << " \n";
	for (const auto& symbol : this->symbolsInReel)
	{
		std::cout << symbol << "\n";
	}
}