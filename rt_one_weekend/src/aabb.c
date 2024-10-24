#include <aabb.h>

t_aabb aabb(t_interval x, t_interval y, t_interval z)
{
	t_aabb new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
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
	return (new);
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

int bvh_hit(t_bvh *node, t_ray r, t_interval ray_t, t_hitrecord *rec)
{
	int hit_left;
	int hit_right;
	if (!aabb_hit(node->bbox, r, ray_t))
		return (0);
	if (node->left->object)
	{
		hit_left = hit(node->left->object, r, ray_t, rec);
		if (hit_left)
			hit_right = hit(node->right->object, r, inv(ray_t.min, rec->t), rec);
		else
			hit_right = hit(node->right->object, r, inv(ray_t.min, ray_t.max), rec);	
		return (hit_left || hit_right);
	}
	else
	{
		hit_left = bvh_hit(node->left, r, ray_t, rec);
		if (hit_left)
			hit_right = bvh_hit(node->right, r, inv(ray_t.min, rec->t), rec);
		else
			hit_right = bvh_hit(node->right, r, inv(ray_t.min, ray_t.max), rec);
		return (hit_left || hit_right);
	}
}
