#pragma once
#include <iostream>
#include <string>

enum SYMBOLS {
	SEVEN,
	BAR,
	WATERMELON,
	BELL,
	PEACH,
	ORANGE,
	CHERRY,
	LEMON
};

class Symbol
{
	int const ID;
	std::string const SIGN;

public:

	Symbol(int _ID, std::string _SIGN)
		: ID(_ID), SIGN(_SIGN)
	{

	}

	Symbol(const Symbol& other)
		: Symbol(other.ID, other.SIGN)
	{
	}

	Symbol(Symbol&& other) noexcept
	//	: ID(std::exchange(other.ID, 0)),
	:	  ID(other.ID), SIGN(std::move(other.SIGN))
	{
	}

	void printSymbol()
	{
		std::cout << this->SIGN;
	}

};

