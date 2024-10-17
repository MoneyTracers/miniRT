#ifndef RAY_H
#define RAY_H

#include "vec3.h"

typedef struct s_vec3 t_vec3;
typedef struct s_ray t_ray;

typedef struct s_ray
{
	t_vec3 org;
	t_vec3 dir;
}t_ray;

void def_ray(t_ray *ray);
void par_ray(t_ray *ray, t_vec3 org, t_vec3 dir);
t_vec3 ray_at(t_ray ray, double t);

#endif
