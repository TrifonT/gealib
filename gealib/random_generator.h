#ifndef RANDOM_GENERATOR_H
#define RANDOM_GENERATOR_H

#include "typedefs.h"

namespace gealib
{	
	namespace random_generator
	{		
		bool get_bool();
		int get_int(int min, int max);
		size_t get_long(size_t min, size_t max);
		ftype get_float();
		ftype get_float(ftype min, ftype max);
	}
}

#endif // ! RANDOM_GENERATOR_H