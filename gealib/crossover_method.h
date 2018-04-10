#pragma once
#include "chromosome.h"
class crossover_method
{
public:
	virtual chromosome crossover(const chromosome* a, const chromosome* b)
	{
		return chromosome();
	}
};

