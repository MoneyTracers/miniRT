#include "hittable.h"

int hit(const t_vec3 *center, const t_ray *ray, double radius, double ray_tmin, double ray_tmax, t_hitrecord*rec)
{
	t_vec3 oc;
	double a;
	double h;
	double c;
	double discriminant;
	double sqrtd;
	double root;

	vec_class_init(&oc);
	oc.copy(&oc, center);
	oc.vded(&oc, ray->org);
	a = ray->dir->lensqr(ray->dir);
	h = dot(ray->dir, &oc);
	c = oc.lensqr(&oc) - (radius*radius);
	discriminant = (h * h) - (a *c);
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	root = (h - sqrtd) / a;
	if (root <= ray_tmin || ray_tmax <= root)
	{
		root = (h + sqrtd) / a;
		if (root <= ray_tmin || ray_tmax <= root)
			return (0);
	}
	rec->t = root;
	rec->p = ray->at(&ray, rec->t);
	rec->normal.copy(&rec->normal, &rec->p);
	rec->normal.vded(&rec->normal, center);
	rec->normal.vdiv(&rec, radius);
	return (1);
}
