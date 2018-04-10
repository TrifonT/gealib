// gen_alg.cpp : Defines the entry point for the console application.
//

#include <vector>
#include "gealib.h"

using namespace std;
using namespace gealib;

# define PI 3.14159265358979323846

double neuralnet(vector<double>& v)
{
	double w13 = v[0];
	double w14 = v[1];
	double w23 = v[2];
	double w24 = v[3];
	double tr3 = v[4];
	double tr4 = v[5];

	double w35 = v[6];
	double w36 = v[7];
	double w45 = v[8];
	double w46 = v[9];
	double tr5 = v[10];
	double tr6 = v[11];

	double w57 = v[12];
	double w67 = v[13];

	vector<double> inp1 = { 0, 1, 0, 1 };
	vector<double> inp2 = { 0, 0, 1, 0 };
	vector<double> targ = { 0, 1, 1, 0 };

	double sum = 0;
	for (int i = 0; i < 3; i++)
	{
		double f3 = (w13 * inp1[i] + w23 * inp2[i] > tr3) ? 0 : 1;
		double f4 = (w14 * inp1[i] + w24 * inp2[i] > tr4) ? 0 : 1;

		double f5 = (w35 * f3 + w45 * f4 > tr5) ? 0 : 1;
		double f6 = (w36 * f3 + w46 * f4 > tr6) ? 0 : 1;

		double f7 = (w57 * f5 + w67 * f6);
		sum +=  pow((targ[i] - f7), 2);
	}

	return (1/(1+sum));
}


// This is the fitness function we want to maximize
double myfunction(vector<double>& v)
{
	double x = v[0];
	double y = v[1];
	double z = v[2];

	return sin(1.3 * x*PI + 1.33 * cos(10 * y*PI + 0.01 * cos(0.22* z*PI))) + sin(z * 2) + 0.01*(x + y + z);
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
