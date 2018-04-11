#include "util.h"
#include <math.h>
#include <type_traits>

using namespace gealib;

#pragma warning(push)
#pragma warning(disable:4244)

longint gealib::uround(ftype val)
{
	if (std::is_same<ftype, double>::value)
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