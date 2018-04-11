#ifndef MUTATION_H
#define MUTATION_H

#include "chromosome.h"

namespace gealib
{
	class mutation
	{
	public:
		ftype probability;
		virtual void mutate(chromo_ptr chrome) const = 0;
	};
}

#endif // ! MUTATION_H

