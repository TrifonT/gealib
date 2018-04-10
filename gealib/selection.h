#ifndef SELECTION_H
#define SELECTION_H

#include "chromosome.h"

namespace gealib
{
	class selection
	{
	public:
		virtual void select(chromo_vec& current, chromo_vec& selected) = 0;
	};

}

#endif // !SELECTION_H

