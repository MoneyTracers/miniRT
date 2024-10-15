#include <rt.h>
#include <strings.h>

void set_face_normal(t_hitrecord **rec, const t_ray *ray, t_vec3 *outward_normal)
{
	t_hitrecord *temp;

	temp = *rec;
	temp->front_face = dot(ray->dir, outward_normal) < 0;
	if (temp->front_face)
	{
		VectorCopy(&temp->normal, outward_normal);
	}
	else
	{
		VectorCopy(&temp->normal, outward_normal);
		OperatorMinus(&temp->normal);
	}
}
int hit_check(t_hittable *world, t_ray *ray, double ray_tmin, double ray_tmax, t_hitrecord**rec)
{
	t_hitrecord *temp_rec;
	int			hit_anything;
	double		closest_so_far;

	hit_anything = 0;
	closest_so_far = ray_tmax;
	temp_rec = calloc(1, sizeof(t_hitrecord));
	while (world)
	{
		if (hit(&world->center, ray, world->radius, ray_tmin, ray_tmax, temp_rec))
		{
			hit_anything = 1;
			closest_so_far = temp_rec->t;
			free(*rec);
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}



int hit(t_vec3 *center, t_ray *ray, double radius, double ray_tmin, double ray_tmax, t_hitrecord *rec)
{
	t_vec3 oc;
	t_vec3 outward_normal;
	double a;
	double h;
	double c;
	double discriminant;
	double sqrtd;
	double root;

	VectorCopy(&oc, center);
	VectorDeduction(&oc, ray->org);
	a = VectorLengthSquared(ray->dir);
	h = dot(ray->dir, &oc);
	c = VectorLengthSquared(&oc) - (radius*radius);
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
	rec->p = RayAt(ray, rec->t);
	VectorCopy(&outward_normal, &rec->p);
	VectorDeduction(&outward_normal, center);
	VectorDivide(&outward_normal, radius);
	set_face_normal(&rec, ray, &outward_normal);
	VectorCopy(&rec->normal, &rec->p);
	VectorDeduction(&rec->normal, center);
	VectorDivide(&rec->normal, radius);
	return (1);
}
