#include <rt.h>
#include <stdlib.h>

double degrees_to_radians(double degrees)
{
	return (degrees * pi / 180.0);
}

double random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double random_double_between(double min, double max)
{
	return (min + (max-min) * random_double());
}