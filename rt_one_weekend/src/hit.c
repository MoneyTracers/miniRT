#include <rt.h>
#include <strings.h>

void set_face_normal(t_hitrecord **rec, const t_ray *ray, t_vec3 *outward_normal)
{
	t_hitrecord *temp;

	temp = *rec;
	temp->front_face = dot(ray->dir, *outward_normal) < 0;
	if (temp->front_face)
	{
		temp->normal = *outward_normal;
	}
	else
	{
		temp->normal = *outward_normal;
		temp->normal = vec_mul(temp->normal, -1);
	}
}

//change hit function to bvh hit function
int hit_check(t_hittable *world, t_ray ray, t_interval ray_i, t_hitrecord*rec)
{
	t_hittable *temp;
	t_hitrecord temp_rec;
	int			hit_anything;
	double		closest_so_far;

	hit_anything = 0;
	closest_so_far = ray_i.max;
	temp = world;
	while (temp)
	{
		if (hit(temp, ray, inv(ray_i.min, closest_so_far), &temp_rec))
		{
			hit_anything = 1;
			closest_so_far = temp_rec.t;
			*rec = temp_rec;
		}
		temp = temp->next;
	}
	return (hit_anything);
}



int hit(t_hittable *world ,t_ray ray, t_interval ray_i, t_hitrecord *rec)
{
	t_vec3 oc;
	t_vec3 outward_normal;
	double a;
	double h;
	double c;
	double discriminant;
	double sqrtd;
	double root;

	oc = world->center;
	oc = vec_sub(oc, ray.org);
	a = vec_len_sqr(ray.dir);
	h = dot(ray.dir, oc);
	c = vec_len_sqr(oc) - (world->radius*world->radius);
	discriminant = (h * h) - (a *c);
	if (discriminant < 0)
		return (0);
	sqrtd = sqrt(discriminant);
	root = (h - sqrtd) / a;
	if (!surround(ray_i, root))
	{
		root = (h + sqrtd) / a;
		if (!surround(ray_i, root))
			return (0);
	}
	rec->t = root;
	rec->p = ray_at(ray, rec->t);
	outward_normal = vec_div(vec_sub(rec->p, world->center), world->radius);
	set_face_normal(&rec, &ray, &outward_normal);
	rec->mat = world->mat;
	return (1);
}
