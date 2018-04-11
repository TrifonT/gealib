#include "mutation_singlebit.h"

void gealib::mutation_singlebit::mutate(chromo_ptr chromo) const
{
	size_t sz = chromo->size();
	for (int i = 0; i < sz; i++)
		if (random_generator::get_float()< probability)
			chromo->flip(i);
}
