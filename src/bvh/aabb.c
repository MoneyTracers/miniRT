/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:50:57 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 18:03:02 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <aabb.h>
#include <interval.h>

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

t_aabb aabb_vec(t_tuple a, t_tuple b)
{
	t_aabb new;

	if (a.x <= b.x)
		new.x = inv(a.x, b.x);
	else
		new.x = inv(b.x, a.x);
	if (a.y <= b.y)
		new.y = inv(a.y, b.y);
	else
		new.y = inv(b.y, a.y);
	if (a.z <= b.z)
		new.z = inv(a.z, b.z);
	else
		new.z = inv(b.z, a.z);
	return (pad_to_minimus(new));
}

t_aabb aabb_const(t_aabb a, t_aabb b)
{
	t_aabb new;

	new.x = inv_const(a.x, b.x);
	new.y = inv_const(a.y, b.y);
	new.z = inv_const(a.z, b.z);
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