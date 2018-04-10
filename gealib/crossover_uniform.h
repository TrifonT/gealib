#ifndef CROSSOVER_UNIFORM_H
#define CROSSOVER_UNIFORM_H

#include "crossover.h"

namespace gealib
{
	class xo_uniform : public crossover
	{
	public:
		chromo_ptr cross(chromo_ptr a, chromo_ptr b) override;
	};
}

#endif // !CROSSOVER_UNIFORM_H


