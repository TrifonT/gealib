#include "chromosome.h"

using namespace gealib;

// Parameterless constructor

chromosome::chromosome() : vector<bool>()
{
}

// Creates a chromosome of specidied size

chromosome::chromosome(size_t size) : vector<bool>(size)
{
}

// Encodes an area of the chromosome as integer

longint chromosome::get(size_t pos, size_t bits)
{
	longint val = 0;
	longint bit = 1;
	for (size_t i = pos; i < pos + bits; i++, bit <<= 1)
		if (at(i))
			val |= bit;
	return val;
}

// Sets an area of the chromosome decoding an integer

void chromosome::set(size_t pos, size_t bits, longint value)
{
	longint bit = 1;
	for (size_t i = pos; i < pos + bits; i++, bit <<= 1)
		at(i) = ((bit & value) > 0);
}

// Flips a single bit at index location

void chromosome::flip(size_t index)
{
	this->at(index) = !this->at(index);
}

// Fills chromosome with random values

void chromosome::randomize()
{
	for (auto it = begin(); it != end(); ++it)
	{
		*it = random_generator::get_bool();
	}
}

// Converts chromosome to a string of 0/1

std::string chromosome::to_string()
{
	std::stringstream ss;
	for (auto it = begin(); it != end(); it++)
		ss << ((*it) ? "1" : "0");
	return ss.str();
}
