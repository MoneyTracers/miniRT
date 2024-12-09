/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cylinder.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/27 14:42:50 by maraasve      #+#    #+#                 */
/*   Updated: 2024/12/09 13:32:25 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <list.h>

bool	check_cap(t_ray ray, float t, float radius)
{
	float	x;
	float	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((powf(x, 2) + powf(z, 2)) <= powf(radius, 2));
}

bool	intersect_caps(t_intersect **head, t_object *object, t_ray ray)
{
	float	t;
	float	radius;

	if (!object->cylinder->capped || equal_float(ray.direction.y, 0))
		return (SUCCESS);
	radius = 1;
	t = (object->cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, radius))
	{
		if (add_intersect_sorted(head, new_intersect(t, object)) == ERROR)
			return (ERROR);
	}
	t = (object->cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, radius))
	{
		if (add_intersect_sorted(head, new_intersect(t, object)) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	cyl_algo(t_intersect **head, t_ray ray, t_object *obj, float val[3])
{
	float	discriminant;
	float	t;
	float	y;

	discriminant = get_discriminant(val[A], val[B], val[C]);
	if (discriminant >= 0)
	{
		t = (-val[B] - sqrtf(discriminant)) / (2 * val[A]);
		y = ray.origin.y + t * ray.direction.y;
		if (y > obj->cylinder->min && y < obj->cylinder->max)
		{
			if (add_intersect_sorted(head, new_intersect(t, obj)) == ERROR)
				return (ERROR);
		}
		t = (-val[B] + sqrtf(discriminant)) / (2 * val[A]);
		y = ray.origin.y + t * ray.direction.y;
		if (y > obj->cylinder->min && y < obj->cylinder->max)
		{
			if (add_intersect_sorted(head, new_intersect(t, obj)) == ERROR)
				return (ERROR);
		}
	}
	if (intersect_caps(head, obj, ray) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	intersect_cylinder(t_intersect **head, t_ray ray, t_object *object)
{
	float	val[3];

	val[A] = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
	val[B] = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z \
			* ray.direction.z;
	val[C] = powf(ray.origin.x, 2) + powf(ray.origin.z, 2) - 1;
	if (cyl_algo(head, ray, object, val) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
