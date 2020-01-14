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

	Symbol(Symbol&& other) 
		: 
};

