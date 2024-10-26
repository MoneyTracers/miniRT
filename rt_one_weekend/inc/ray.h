#ifndef RAY_H
#define RAY_H

#include <rt.h>

typedef struct s_vec3 t_vec3;
typedef struct s_ray t_ray;

typedef struct s_ray
{
	t_vec3 org;
	t_vec3 dir;
	double time;
}t_ray;

t_ray def_ray(void);
t_ray par_ray(t_vec3 org, t_vec3 dir);
t_vec3 ray_at(t_ray ray, double t);
t_ray par_ray_time( t_vec3 org, t_vec3 dir, double time);

#endif

