#include <rt.h>

t_aabb aabb(t_interval x, t_interval y, t_interval z)
{
	t_aabb new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_interval expand(t_interval axis_inter, double delta)
{
	double padding;

	padding = delta / 2;
	return (inv(axis_inter.min - padding, axis_inter.max + padding));
}

t_aabb pad_to_minimus(t_aabb bbox)
{
	double delta;

	delta = 0.0001;
	if (size(bbox.x) < delta)
		bbox.x = expand(bbox.x, delta);
	if (size(bbox.y) < delta)
		bbox.y = expand(bbox.y, delta);
	if (size(bbox.z) < delta)
		bbox.z = expand(bbox.z, delta);
	return (bbox);
}

t_aabb aabb_vec(t_vec3 a, t_vec3 b)
{
	t_aabb new;

	if (a.e[0] <= b.e[0])
		new.x = inv(a.e[0], b.e[0]);
	else
		new.x = inv(b.e[0], a.e[0]);
	if (a.e[1] <= b.e[1])
		new.y = inv(a.e[1], b.e[1]);
	else
		new.y = inv(b.e[1], a.e[1]);
	if (a.e[2] <= b.e[2])
		new.z = inv(a.e[2], b.e[2]);
	else
		new.z = inv(b.e[2], a.e[2]);
	return (pad_to_minimus(new));
}

t_aabb aabb_aabb(t_aabb a, t_aabb b)
{
	t_aabb new;

	new.x = inv_inv(a.x, b.x);
	new.y = inv_inv(a.y, b.y);
	new.z = inv_inv(a.z, b.z);
	return (new);
}

t_interval axis_interval(t_aabb aabb, int n)
{
	if (n == 1)
		return(aabb.y);
	if (n == 2)
		return(aabb.z);
	return(aabb.x);
}

int aabb_hit(t_aabb aabb, t_ray r, t_interval ray_t)
{
	int axis;
	t_interval ax;
	double adinv;
	double t0;
	double t1;

	axis = 0;
	while (axis < 3)
	{
		ax = axis_interval(aabb, axis);
		adinv = 1 / r.dir.e[axis];
		t0 = (ax.min - r.org.e[axis]) *adinv;
		t1 = (ax.max - r.org.e[axis]) *adinv;
		
		if (t0 < t1)
		{
			if (t0 > ray_t.min)
				ray_t.min = t0;
			if (t1 < ray_t.max)
				ray_t.max = t1;
		}
		else 
		{
			if (t1 > ray_t.min)
				ray_t.min = t1;
			if (t0 < ray_t.max)
				ray_t.max = t0;
		}
		if (ray_t.max <= ray_t.min)
			return (0);
		axis++;
	}
	return (1);
}
