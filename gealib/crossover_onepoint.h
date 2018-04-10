#ifndef CROSSOVER_ONEPOINT_H
#define CROSSOVER_ONEPOINT_H

#include "crossover.h"

namespace gealib
{
	class crossover_onepoint : public crossover
	{
	public:
		chromo_ptr cross(chromo_ptr a, chromo_ptr b) override;
	};
}

#endif // !CROSSOVER_ONEPOINT_H

