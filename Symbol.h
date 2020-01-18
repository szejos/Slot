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
	}

	Symbol& operator=(const Symbol& other) 
	{	
		if (this != &other)
		{
			id = other.id;
			sign = other.sign;
			return *this;// = Symbol(other);
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
	bool operator==(const Symbol& other) const
	{ 
		if (this->id == other.id)
		{
			return true;
		}
		return false;
	}
	bool operator>(const Symbol& other) const
	{
		if (this->id > other.id)
		{
			return true;
		}
		return false;
	}
	bool operator<(const Symbol& other) const
	{
		if (this->id < other.id)
		{
			return true;
		}
		return false;
	}
	bool operator>=(const Symbol& other) const
	{
		if (this->id >= other.id)
		{
			return true;
		}
		return false;
	}
	bool operator<=(const Symbol& other) const
	{
		if (this->id <= other.id)
		{
			return true;
		}
		return false;
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

