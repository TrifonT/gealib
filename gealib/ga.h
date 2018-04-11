#ifndef GA_H
#define GA_H

using namespace std;
#include "gealib.h"

namespace gealib
{
	class ga
	{
	private:
		parameters params;
		ftype erate = 0.1f;
		ftype mrate = 0.03f;
		ftype crate = 0.5f;

		size_t chrsize;
		size_t popsize;
		size_t crosize;
		size_t eltsize;

		chromo_vec current;

		fitness_function fitfunction;

		crossover_onepoint op;
		crossover& crossover_ref;
		mutation_singlebit sb;
		mutation& mutation_ref;
		selection_rws so;
		selection& selection_ref;
	public:

		ga(fitness_function func, size_t popsize = 1024, ftype mutrate = 0.1, ftype crossrate = 0.5f,
			 ftype eliterate = 0.1);

		// Adds a parameter to the genetic algorithm
		void add_parameter(parameter param);

		// Constructs and then adds a parameter to the genetic algorithm
		parameter add_parameter(string name, ftype min, ftype max, ftype step);

		// Gets the mutation rate
		ftype get_mutation_rate();

		// Sets the mutation rate
		void set_mutation_rate(ftype rate);

		// Gets the crossover rate
		ftype get_crossover_rate();

		// Sets the crossover rate
		void set_crossover_rate(ftype rate);

		// Gets the elite rate
		ftype get_elite_rate();

		// Sets the elite rate
		void set_elite_rate(ftype rate);

		// Gets population size
		size_t get_population_size();

		// Sets population size
		void set_population_size(size_t pop_size);

		// Gets fitness function
		fitness_function get_fitness_function();

		// Sets fitness function
		void set_fitness_function(fitness_function function);

		// Gets the crossover method
		crossover& get_crossover();

		// Sets the crossover method
		void set_crossover(crossover& crossover);

		// Gets the mutation method
		mutation& get_mutation();

		// Sets the mutation method
		void set_mutation(mutation& mutation);

		// Initializes the ga instance before optimization
		void init();

		// Evaluates current population
		void evaluate();

		// Sorts current population by the fitness function result
		void sort_current();

		// Performs an optimization step
		void step();

		// Runs optimization
		void run(size_t iterations = 100, size_t disp_progress = 10, bool show_results = true);

		// Displays progress among iterations
		void display_progress(size_t iteration);

		// Prints optimized parameters
		void print_params();

	};
}


#endif // !GA_H