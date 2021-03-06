#include "parameter.h"
#include <memory>
#include <assert.h>
#include <algorithm>
#include "util.h"

using namespace gealib;

void parameter::compute_steps(ftype step)
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

parameter::parameter(std::string parname, ftype minv, ftype maxv, ftype step) : name(parname), min(minv), max(maxv)
{
	compute_steps(step);
}

parameter::parameter(ftype minv, ftype maxv, ftype step) : name(""), min(minv), max(maxv)
{
	compute_steps(step);
}

ftype parameter::get(const chromo_ptr chromo, size_t pos) const
{
	longint val = chromo->get(pos, bits);
	return  std::min((min + val * fstep), max);
}

void parameter::set(chromo_ptr chromo, size_t pos, ftype rval) const
{
	longint ival = uround((rval - min) / fstep);
	chromo->set(pos, bits, ival);
}