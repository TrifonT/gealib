#ifndef PARAMETER_H
#define PARAMETER_H

#include <string>
#include "typedefs.h"
#include "chromosome.h"


namespace gealib
{
	// Represents a computed parameter
	class parameter
	{
	private:
		// Computes steps among min and max
		void compute_steps(float_t step);
	public:
		// Name of the parameter
		std::string	name;

		// Lower limit of parameter value
		float_t	min;

		// Upper limit of parameter value
		float_t	max;

		// Optimized parameter value
		float_t	value;

		// Step for parameter values
		float_t	fstep;

		// Number of chromosome bits to use
		int	bits;

		// Number of steps that (max-min) is divided into
		longint	steps;

		// Create a new parameter specifying its name, min, max values 
		// and required accuracy
		parameter(std::string name, float_t min, float_t max, float_t step);

		// Create a new paramter specifying min, max and accuracy
		parameter(float_t min, float_t max, float_t step);

		// Gets the value of the parameter from a specified chromosome position
		float_t get(std::shared_ptr<chromosome> chromo, size_t pos);

		// Writes a value for the parameter in a specified chromosome position
		void set(std::shared_ptr<chromosome> chromo, size_t pos, float_t rval);
	};

	using parameters = std::vector<parameter>;

}
#endif // !PARAMETER_H