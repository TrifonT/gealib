#ifndef CROSSOVER_UNIFORM_H
#define CROSSOVER_UNIFORM_H

#include "crossover.h"

namespace gealib
{
	class xo_uniform : public crossover
	{
	public:
		chromo_ptr cross(const chromo_ptr a, const chromo_ptr b) const override;
	};
}

#endif // !CROSSOVER_UNIFORM_H


