
#include "random_generator.h"
#include <random>

namespace gealib
{
	namespace random_generator
	{
		thread_local std::random_device rd;
		static thread_local std::default_random_engine re = std::default_random_engine(rd());
		thread_local std::uniform_int_distribution<int> bd = std::uniform_int_distribution<int>(0, 1);
		thread_local std::uniform_real_distribution<float_t> fd = std::uniform_real_distribution<float_t>(0.0f, 1.0f);

		bool get_bool()
		{
			return (bd(re) == 1);
		}

		int get_int(int min, int max)
		{
			std::uniform_int_distribution<int> id(min, max);
			return id(re);
		}

		size_t get_long(size_t min, size_t max)
		{
			std::uniform_int_distribution<size_t> id(min, max);
			return id(re);
		}

		float_t get_float()
		{
			return fd(re);
		}

		float_t get_float(float_t min, float_t max)
		{
			std::uniform_real_distribution<float_t> f(min, max);
			return f(re);
		}
	}
}

