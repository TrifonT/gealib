#include "selection_rws.h"

#include <vector>
#include <algorithm>
#include "typedefs.h"

void gealib::selection_rws::select(chromo_vec & current, chromo_vec & selected)
{
	size_t count = selected.size();
	std::vector<float_t> values;
	values.reserve(current.size());
	float_t minv = DBL_MAX;
	std::for_each(current.begin(), current.end(), [&minv, &values](chromo_ptr p){
		float_t f = p->fitness;
		values.push_back(f); 
		minv = std::min(minv, f); 
	});

	float_t fsum = 0;
	std::for_each(values.begin(), values.end(), [&fsum, minv](float_t& val)
	{	
		val += (fsum - minv);
		fsum = val;	
	});

	for (int i = 0; i < count; i++)
	{
		float_t d = random_generator::get_float(0, fsum);
		auto it = std::lower_bound(values.begin(), values.end(), d);
		size_t idx = it - values.begin();
		selected[i] = current[idx];
	}
}
