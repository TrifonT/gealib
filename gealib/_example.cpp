// gen_alg.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>
#include "gealib.h"

using namespace std;
using namespace gealib;

# define PI 3.14159265358979323846

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

	// Define the parameters. Name, min, max
	// value and required accuracy (step)
	parameter x("x", -1.0, 1.0, 0.000001);
	parameter y("y", -1.0, 1.0, 0.000001);
	parameter z("z", -1.0, 1.0, 0.000001);

	// Add parameters to the genetic algorithm
	ga.add_parameter(x);
	ga.add_parameter(y);
	ga.add_parameter(z);

	// run 500 iterations, show progress 
	// every 50 iterations
	ga.run(500, 50);

	getchar();
	return 0;
}

