#include "ray.h"

void DefaultRayConstructor(t_ray *ray)
{
	t_vec3 *dir;
	t_vec3 *orig;

	dir = malloc(sizeof(t_vec3));
	orig = malloc(sizeof(t_vec3));
	vec_class_init(dir);
	vec_class_init(orig);
	dir->def_const(dir);
	ray->dir = dir;
	orig->def_const(orig);
	ray->org = orig;
}

void ParamRayConstructor(t_ray *ray, t_vec3 *org, t_vec3 *dir)
{
	ray->dir = dir;
	ray->org = org;
}

const t_vec3* RayOrigin(t_ray *ray)
{
	return((const t_vec3*)ray->org);
}

const t_vec3* RayDirection(t_ray *ray)
{
	return((const t_vec3*)ray->dir);
}

t_vec3 RayAt(t_ray *ray, double t)
{
	t_vec3 vec;
	vec_class_init(&vec);
	vec.copy(&vec, ray->dir);
	vec.vmul(&vec, t);
	vec.vadd(&vec, ray->org);
	return (vec);
}

void ray_class_init(t_ray *ray)
{
	ray->def_const = &DefaultRayConstructor;
	ray->par_const = &ParamRayConstructor;
	ray->ray_orig = &RayOrigin;
	ray->ray_dir = &RayDirection;
	ray->at = &RayAt;
}

