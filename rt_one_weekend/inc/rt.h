#ifndef RT_H
#define RT_H

#include <color.h>
#include <hittable.h>
#include <ray.h>
#include <vec3.h>
#include <interval.h>
#include <camera.h>
#include <material.h>
# include <math.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <aabb.h>

#define pi 3.1415926535897932385

double degrees_to_radians(double degrees);
double random_double(void);
double random_double_between(double min, double max);

#endif


