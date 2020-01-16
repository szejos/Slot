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

void Reel::printReel()
{
	//std::copy(this->symbolsInReel.begin(),
	//		  this->symbolsInReel.end(),
	//	      std::ostream_iterator<std::string>(std::cout, " \n "));
	for (auto it = this->symbolsInReel.begin(); it != this->symbolsInReel.end(); ++it)
	{
		std::cout << *it << "\n";
	}

}