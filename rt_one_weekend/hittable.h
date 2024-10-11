#ifndef HITTABLE_H
#define HITTABLE_H


#include "ray.h"
#include "vec3.h"

typedef struct s_hitrecord
{
	t_vec3 p;
	t_vec3 normal;
	double t;
}t_hitrecord;

int hit(const t_ray *ray, double ray_tmin, double ray_tmax, t_hitrecord*rec);

#endif
