#ifndef CROSSOVER_ONEPOINT_H
#define CROSSOVER_ONEPOINT_H

#include "crossover.h"

namespace gealib
{
	class crossover_onepoint : public crossover
	{
	public:
		chromo_ptr cross(const chromo_ptr a, const chromo_ptr b) const override;
	};
}

#endif // !CROSSOVER_ONEPOINT_H

