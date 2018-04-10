#include "parameter.h"
#include <memory>
#include <assert.h>
#include <algorithm>
#include "util.h"

using namespace gealib;

void parameter::compute_steps(float_t step)
{
	assert(step <= max - min);
	longint s = uround((max - min) / step);
	bits = 0;
	for (longint i = 1; i < s; i <<= 1)
		bits++;
	assert(bits <= sizeof(steps)*CHAR_BIT);
	steps = ((1ull) << bits);
	fstep = (max - min) / s;
}

parameter::parameter(std::string parname, float_t minv, float_t maxv, float_t step) : name(parname), min(minv), max(maxv)
{
	compute_steps(step);
}

parameter::parameter(float_t minv, float_t maxv, float_t step) : name(""), min(minv), max(maxv)
{
	compute_steps(step);
}

float_t parameter::get(std::shared_ptr<chromosome> chromo, size_t pos)
{
	longint val = chromo->get(pos, bits);
	return  std::min((min + val * fstep), max);
}

void parameter::set(std::shared_ptr<chromosome> chromo, size_t pos, float_t rval)
{
	longint ival = uround((rval - min) / fstep);
	chromo->set(pos, bits, ival);
}