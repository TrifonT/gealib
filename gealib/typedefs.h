#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include <vector>

#define float_t double
#define longint unsigned long long

// fitness function prototype
typedef float_t(*fitness_function)(std::vector<float_t>&);

#endif // ! TYPEDEFS_H

