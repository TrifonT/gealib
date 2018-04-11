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
		void compute_steps(ftype step);
	public:
		// Name of the parameter
		std::string	name;

		// Lower limit of parameter value
		ftype	min;

		// Upper limit of parameter value
		ftype	max;

		// Optimized parameter value
		ftype	value;

		// Step for parameter values
		ftype	fstep;

		// Number of chromosome bits to use
		int	bits;

		// Number of steps that (max-min) is divided into
		longint	steps;

		// Create a new parameter specifying its name, min, max values 
		// and required accuracy
		parameter(std::string name, ftype min, ftype max, ftype step);

		// Create a new paramter specifying min, max and accuracy
		parameter(ftype min, ftype max, ftype step);

		// Gets the value of the parameter from a specified chromosome position
		ftype get(const chromo_ptr chromo, size_t pos) const;

		// Writes a value for the parameter in a specified chromosome position
		void set(chromo_ptr chromo, size_t pos, ftype rval) const;
	};

	using parameters = std::vector<parameter>;

}
#endif // !PARAMETER_H