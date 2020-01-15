#pragma once
#include <iostream>
#include <string>

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
		: id(symbolsEnum::EMPTY), sign("")
	{}

	Symbol(symbolsEnum const& _id, std::string const& _sign)
		: id(_id), sign(_sign)
	{}

	Symbol(const Symbol& other)
		: Symbol(other.id, other.sign)
	{}

	Symbol& operator=(const Symbol& other)
	{
		return *this = Symbol(other);
	}

	Symbol(Symbol&& other) noexcept
		: id(std::move(other.id)),
		  sign(std::move(other.sign))
	{}

	~Symbol()
	{}

	std::string getSymbol()
	{
		return this->sign;
	}

	symbolsEnum getid()
	{
		return this->id;
	}

};

