# gealib
A fast parallel genetic algorithm implementation in C++.

## Code example
```C++
#include <vector>
#include "gealib.h"

using namespace std;
using namespace gealib;

# define PI 3.14159265358979323846

// This is the fitness function we want to maximize
double myfunction(vector<double>& v)
{
	double x = v[0];
	double y = v[1];
	double z = v[2];

	return sin(1.3 * x*PI + 1.33 * cos(10 * y*PI + 0.01 * cos(0.22* z*PI))) + sin(z * 2) + 0.01*( x + y + z);
}

int main()
{
	// create an instance of the ga class 
	// specifying the fitness function
	ga ga(myfunction);

	// Define the parameters by name, min and max value, required accuracy
	parameter x("x", -1.0, 1.0, 0.000001);
	parameter y("y", -1.0, 1.0, 0.000001);
	parameter z("z", -1.0, 1.0, 0.000001);

	// Add parameters to the genetic algorithm
	ga.add_parameter(x);
	ga.add_parameter(y);
	ga.add_parameter(z);

	// run 500 iterations, show progress every 50 iterations
	ga.run(500, 50);

	getchar();
	return 0;
}

```
## Genetic Algorithm parameters
The above example runs with the default parameters. The following parameters can be specified with set methods.
### Mutation Rate
Specifies the probability of chromosome mutation 
```C++
ga.set_mutation_rate(0.03);
```
### Crossover Rate
Specifies the percentage of the population that participates in crossover
```C++
ga.set_crossover_rate(0.5);
```
### Elite Rate
Specifies the percentage of the population that participates in next generation without crossover.
```C++
ga.set_elite_rate(0.1);
```
### Population Size
Specifies the size of the chromosome population.
```C++
ga.set_population_size(1024);
```
### Fitness Function
Specifies the fitness function to be used
```C++
ga.set_fitness_function(function);
```
### Set Crossover Method
Specifies the crossover method to be used. Should be an instance of a class inheriting from `gealib::crossover`.
```C++
ga.set_crossover(crossover);
```
### Set Mutation Method
Specifies the mutation method to be used. Should be an instance of a class inheriting from `gealib::mutation`.
```C++
ga.set_mutation(mutation);
```


