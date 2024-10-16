#include <rt.h>

void def_ray(t_ray *ray)
{
	ray->dir = dvec();
	ray->org = dvec();
}

void par_ray(t_ray *ray, t_vec3 org, t_vec3 dir)
{
	ray->dir = dir;
	ray->org = org;
}

t_vec3 ray_at(t_ray ray, double t)
{
	return (vec_add(vec_mul(ray.dir, t), ray.org));
}


