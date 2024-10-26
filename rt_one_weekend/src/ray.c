#include <rt.h>


t_ray def_ray(void)
{
	t_ray ray;

	ray.dir = dvec();
	ray.org = dvec();
	return (ray);
}


t_ray par_ray_time( t_vec3 org, t_vec3 dir, double time)
{
	t_ray ray;

	ray.dir = dir;
	ray.org = org;
	ray.time = time;
	return (ray);
}

t_ray par_ray( t_vec3 org, t_vec3 dir)
{
	return (par_ray_time(org, dir, 0));
}

t_vec3 ray_at(t_ray ray, double t)
{
	return (vec_add(vec_mul(ray.dir, t), ray.org));
}


