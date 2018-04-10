#ifndef MUTATION_H
#define MUTATION_H

#include "chromosome.h"

namespace gealib
{
	class mutation
	{
	public:
		float_t probability;
		virtual void mutate(chromo_ptr chrome) = 0;
	};
}

#endif // ! MUTATION_H

