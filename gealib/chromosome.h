#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <memory>
#include <string>
#include <sstream>
#include "typedefs.h"
#include "random_generator.h"

namespace gealib
{
	// Implements a binary chromosome as a vector
	// of boolean values
	class chromosome : public std::vector<bool>
	{
	public:
		// Parameterless constructor
		chromosome();
		
		// Creates a chromosome of specidied size
		chromosome(size_t size);
		
		// Encodes an area of the chromosome as an integer
		longint get(size_t pos, size_t bits);
		
		// Sets an area of the chromosome decoding an integer
		void set(size_t pos, size_t bits, longint value);
		
		// Flips a single bit at index location
		void flip(size_t index);
		
		// Fills chromosome with random values
		virtual void randomize();
		
		// Converts chromosome to a string of 0/1
		virtual std::string to_string();
		
		// Stores the fitness value of the last evaluation
		float_t fitness;
	};

	using chromo_ptr = std::shared_ptr<chromosome>;
	using chromo_vec = std::vector<chromo_ptr>;

}

#endif // !_CHROMOSOME_H
