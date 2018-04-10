#include "util.h"
#include <type_traits>

using namespace gealib;

#pragma warning(push)
#pragma warning(disable:4244)

longint gealib::uround(float_t val)
{
	if (std::is_same<float_t, double>::value)
	{
		if (sizeof(longint) == 64)
			return std::llround(val);
		else
			return std::lround(val);
	}
	else
	{
		if (sizeof(longint) == 64)
			return std::llroundf(val);
		else
			return std::lroundf(val);
	}
}
#pragma warning(pop)