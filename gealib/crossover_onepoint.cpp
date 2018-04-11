#include "crossover_onepoint.h"
#include <assert.h>
#include "random_generator.h"
#include "chromosome.h"

using namespace gealib::random_generator;

gealib::chromo_ptr gealib::crossover_onepoint::cross(const chromo_ptr a, const chromo_ptr b) const
{
	size_t size = a->size();
	assert(size == b->size());
	size_t pos = get_long(1, size - 1);
	chromo_ptr c = std::make_shared<chromosome>(size);
	for (int i = 0; i < pos; i++)
	{
		c->at(i) = a->at(i);
	}
	for (size_t i = pos; i < size; i++)
	{
		c->at(i) = b->at(i);
	}
	return c;
}
