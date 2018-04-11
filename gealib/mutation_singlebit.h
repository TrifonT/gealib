#ifndef MUTATION_SINGLEBIT_H
#define MUTATION_SINGLEBIT_H

#include "mutation.h"
#include "random_generator.h"

namespace gealib
{
	class mutation_singlebit : public mutation
	{
	public:
		void mutate(chromo_ptr chromo) const override;
	};
}

#endif // ! MUTATION_SINGLEBIT_H

