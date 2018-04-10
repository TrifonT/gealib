#include "crossover_uniform.h"
#include <assert.h>
#include "random_generator.h"

using namespace gealib;

chromo_ptr xo_uniform::cross(chromo_ptr a, chromo_ptr b)
{
	size_t size = a->size();
	assert(size == b->size());
	chromo_ptr c = std::make_shared<chromosome>(size);
	for (size_t i = 0; i < size; i++)
	{
		if (random_generator::get_bool())
			c->at(i) = a->at(i);
		else
			c->at(i) = b->at(i);
	}
	return c;
}
