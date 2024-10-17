#include <rt.h>

t_ray def_ray(void)
{
	t_ray ray;

	ray.dir = dvec();
	ray.org = dvec();
	return (ray);
}

t_ray par_ray( t_vec3 org, t_vec3 dir)
{
	t_ray ray;

	ray.dir = dir;
	ray.org = org;
	return (ray);
}

t_vec3 ray_at(t_ray ray, double t)
{
	return (vec_add(vec_mul(ray.dir, t), ray.org));
}


