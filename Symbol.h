#pragma once
#include "Util.h"

enum class symbolsEnum {
	SEVEN,
	BAR,
	WATERMELON,
	BELL,
	PEACH,
	ORANGE,
	CHERRY,
	LEMON,
	SYMBOLSCOUNT,
	EMPTY
};

class Symbol
{
	symbolsEnum id;
	std::string sign;

public:
	Symbol()
		: id(symbolsEnum::EMPTY), sign(" ")
	{}

	Symbol(symbolsEnum const& _id, std::string const& _sign)
		: id(_id), sign(_sign)
	{}

	Symbol(const Symbol& other)
		: Symbol(other.id, other.sign)
	{
		std::cout << " kopiujacy z other \n";
	}

	Symbol& operator=(const Symbol& other) 
	{	
		std::cout << " K prze ";
		if (this != &other)
		{
			std::cout << "pisujacy\n";
			return *this = Symbol(other);

		}

	}

	Symbol(Symbol&& other) noexcept
		: id(std::move(other.id)),
		  sign(std::move(other.sign))
	{}

	~Symbol()
	{}

	friend std::ostream& operator<<(std::ostream & out, const Symbol& s)
	{
		out << s.sign;
		return out;
	}
	std::string getSymbol()
	{
		return this->sign;
	}

	symbolsEnum getid()
	{
		return this->id;
	}

};

