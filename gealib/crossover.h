#ifndef CROSSOVER_H
#define CROSSOVER_H

#include "chromosome.h"

namespace gealib
{
	class crossover
	{
	public:
		virtual chromo_ptr cross(const chromo_ptr  a, const chromo_ptr  b) const = 0;
	};
}

#endif // !CROSSOVER_H

