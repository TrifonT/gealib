#ifndef CROSSOVER_H
#define CROSSOVER_H

#include "chromosome.h"

namespace gealib
{
	class crossover
	{
	public:
		virtual chromo_ptr cross(chromo_ptr a, chromo_ptr b) = 0;
	};
}

#endif // !CROSSOVER_H

