#include <assert.h>
#include <ppl.h>
#include "ga.h"
#include "crossover.h"
#include "chromosome.h"

using namespace gealib;
using namespace concurrency;

gealib::ga::ga(fitness_function func, size_t popsize, float_t crossrate, float_t mutrate, float_t eliterate) :
	fitfunction(func),
	popsize(popsize),
	crate(crossrate),
	mrate(mutrate),
	erate(eliterate),
	crossover_ref(op),
	mutation_ref(sb),
	selection_ref(so)
{
}

// Adds a parameter to the genetic algorithm
void ga::add_parameter(parameter param)
{
	params.push_back(param);
}

// Gets the mutation rate

float_t ga::get_mutation_rate()
{
	return mrate;
}

// Sets the mutation rate

void ga::set_mutation_rate(float_t rate)
{
	assert(rate >= 0 && rate <= 1.0);
	mrate = rate;
}

// Gets the crossover rate

float_t ga::get_crossover_rate()
{
	return crate;
}

// Sets the crossover rate

void ga::set_crossover_rate(float_t rate)
{
	assert(rate > 0 && rate <= 1.0);
	crate = rate;
}

// Gets the elite rate

float_t ga::get_elite_rate()
{
	return erate;
}

// Sets the elite rate

void ga::set_elite_rate(float_t rate)
{
	assert(rate >= 0 && rate < 1.0);
	erate = rate;
}

// Gets population size

size_t ga::get_population_size()
{
	return popsize;
}

// Sets population size

void ga::set_population_size(size_t pop_size)
{
	popsize = pop_size;
}

// Gets fitness function

fitness_function ga::get_fitness_function()
{
	return fitfunction;
}

// Sets fitness function

void ga::set_fitness_function(fitness_function function)
{
	fitfunction = function;
}

// Gets the crossover method

crossover& ga::get_crossover()
{
	return crossover_ref;
}

// Sets the crossover method

void ga::set_crossover(crossover & crossover)
{
	crossover_ref = crossover;
}

// Gets the mutation method

mutation & ga::get_mutation()
{
	return mutation_ref;
}

// Sets the mutation method

void ga::set_mutation(mutation & mutation)
{
	mutation_ref = mutation;
}

// Initializes the ga instance before optimization

void gealib::ga::init()
{
	if (params.size() == 0)
		throw logic_error("Nothing to do. Add parameters to optimize.");

	size_t bitsum = 0;
	for_each(params.begin(), params.end(), [&bitsum](parameter p) {	bitsum += p.bits; });
	chrsize = bitsum;

	// ensure population size is valid
	if (popsize == 0)
		throw logic_error("Cannot optimize with a population of zero size.");

	// ensure even number of items for crossover
	crosize = uround(popsize* (crate / 2)) * 2;
	if (crosize == 0)
		throw logic_error("Crossover population is zero.");

	// compute the size for the elite population
	eltsize = uround(popsize *erate);

	// initialize the size of the current population
	current.clear();
	current.resize(popsize);

	// randomize the initial chromosome population
	parallel_for_each(current.begin(), current.end(), [bitsum](chromo_ptr& chr)
	{
		chr = make_shared<chromosome>(bitsum);
		chr->randomize();
	});
}

// Evaluates current population

void gealib::ga::evaluate()
{
	assert(fitfunction != nullptr);
	size_t pcount = params.size();
	parameters p = params;
	fitness_function f = fitfunction;
	// for every chromosome of the current population ...
	parallel_for_each(current.begin(), current.end(), [pcount, f, &p](chromo_ptr chr)
	{
		size_t pos = 0;
		// ... get the values of the parameters from chromosome ...
		thread_local vector<float_t> pars(pcount);
		for (size_t i=0;i<pcount;i++)
		{
			pars[i] = p[i].get(chr, pos);
			pos += p[i].bits;
		}
		// ... and then call the fitness function with these parameters
		chr->fitness = f(pars);
	});
}

// Sorts current population by the fitness function result

void gealib::ga::sort_current()
{
	std::sort(current.begin(), current.end(), 
		[](const chromo_ptr a, const chromo_ptr b)
	{ return (a->fitness > b->fitness); });
}

void gealib::ga::step()
{
	chromo_vec childs;
	// insert into children the best (elite) chromosomes from current
	childs.assign(current.begin(), current.begin() + eltsize);
	childs.resize(popsize);

	// select the mating (crossover) chromosomes
	chromo_vec mates(crosize);
	selection_ref.select(current, mates);

	size_t mxsz = crosize - 1;
	crossover& corf = crossover_ref;
	
	// mate chromosomes and create children
	parallel_for(eltsize, popsize, [&childs, mates, mxsz, &corf](size_t i) {
		size_t i1 = random_generator::get_long(0, mxsz);
		size_t i2 = random_generator::get_long(0, mxsz);
		childs[i] = corf.cross(mates[i1], mates[i2]);
	});

	// perform mutation on children
	float_t murate = mrate;
	mutation& mref = mutation_ref;
	mref.probability = mrate;
	parallel_for(eltsize, popsize, [&childs, murate, &mref](size_t i)
	{
		if (murate > random_generator::get_float())
			mref.mutate(childs[i]);
	});



	// ser children as current population
	current.assign(childs.begin(), childs.end());

	// evaluate fitness function for current population
	evaluate();
	
	// sort current population according to fitness value
	sort_current();

	// get the optimal value for each parameter from 
	// the chromosome with greatest fitnesss value.
	size_t pos = 0;
	for (size_t i = 0; i< params.size(); ++i)
	{
		params[i].value = params[i].get(current[0], pos);
		pos += params[i].bits;
	}
}
