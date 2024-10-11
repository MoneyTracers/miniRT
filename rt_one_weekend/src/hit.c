#include <rt.h>

void set_face_normal(t_hitrecord *rec, const t_ray *ray, t_vec3 *outward_normal)
{
	rec->front_face = dot(ray->dir, outward_normal) < 0;
	if (rec->front_face)
		rec->normal.copy(&rec->normal, outward_normal);
	else
	{
		rec->normal.copy(&rec->normal, outward_normal);
		rec->normal.minus(&rec->normal);
	}
}
int hit(t_vec3 *center, t_ray *ray, double radius, double ray_tmin, double ray_tmax, t_hitrecord*rec)
{
	t_vec3 oc;
	t_vec3 outward_normal;
	double a;
	double h;
	double c;
	double discriminant;
	double sqrtd;
	double root;

	vec_class_init(&oc);
	vec_class_init(&outward_normal);
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
	rec->p = ray->at(ray, rec->t);
	outward_normal.copy(&outward_normal, &rec->p);
	outward_normal.vded(&outward_normal, center);
	outward_normal.vdiv(&outward_normal, radius);
	set_face_normal(rec, ray, &outward_normal);
	rec->normal.copy(&rec->normal, &rec->p);
	rec->normal.vded(&rec->normal, center);
	rec->normal.vdiv(&rec->normal, radius);
	return (1);
}
