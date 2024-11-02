/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:39:19 by marieke           #+#    #+#             */
/*   Updated: 2024/11/02 13:28:12 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <transformation.h>

float	get_discriminant(float a, float b, float c)
{
	float	discriminant;
	
	discriminant = powf(b, 2) - 4 * a * c;
	return (discriminant);
}

t_intersection	*new_intersection(float t, t_object *object)
{
	t_intersection *new = malloc(sizeof(t_intersection));
	if (!new)
		return (NULL);
	new->t = t;
	new->object = object;
	new->next = NULL;
	return (new);
}

int	add_intersection_sorted(t_intersection **head, t_intersection *new)
{
	t_intersection	*cur;
	t_intersection	*prev;

	if (!head || !new)
		return (ERROR);
	if (!*head || (*head)->t >= new->t)
	{
		new->next = *head;
		*head = new;
		return (SUCCESS);
	}
	prev = NULL;
	cur = (*head);
	while (cur && cur->t < new->t)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
	return (SUCCESS);
}

int	intersect_plane(t_intersection **head, t_ray ray, t_object *plane)
{
	t_tuple	plane_pos;
	float	t;
	float	denominator;

	denominator = get_dot_product(plane->plane_normal, ray.direction);
	if (ft_abs(denominator) < EPSILON)
		return (SUCCESS);
	plane_pos = multiply_matrix_tuple(plane->base->transformation, create_point(0, 0, 0));
	t = get_dot_product(plane->plane_normal, subtract_tuple(plane_pos, ray.origin)) / denominator;
	if (add_intersection_sorted(head, new_intersection(t, (void *)plane)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

bool check_cap(t_ray ray, float t, float radius) 
{
	float x;
	float z;
	
	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return ((powf(x, 2) + powf(z, 2)) <= powf(radius, 2));
}

bool intersect_caps(t_intersection **head, t_object *shape, t_ray ray) 
{
	float	t;
	float	radius;

	// Return early if cylinder is uncapped or ray direction y is zero (parallel to caps)
	if (!shape->cyl_capped || equal_float(ray.direction.y, 0))
		return (SUCCESS);
	// Check intersection with lower cap at y = cyl_min
	radius = 1;
	if (shape->base->type == CONE)
		radius = fabs(shape->cyl_min);
	t = (shape->cyl_min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, radius))
	{
		if (add_intersection_sorted(head, new_intersection(t, shape)) == ERROR)
			return (ERROR);
	}
	// Check intersection with upper cap at y = cyl_max
	if (shape->base->type == CONE)
		radius = fabs(shape->cyl_max);
	t = (shape->cyl_max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, radius))
	{
		if (add_intersection_sorted(head, new_intersection(t, shape)) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	cyl_cone_algorythm(t_intersection **head, t_ray ray, t_object *shape, float a, float b, float c)
{
	float	discriminant;
	float	t;
	float	y;

	discriminant = get_discriminant(a, b, c);
	if (discriminant >= 0)
	{
		t = (-b - sqrtf(discriminant)) / (2 * a);
		y = ray.origin.y + t * ray.direction.y;
		if (y > shape->cyl_min && y < shape->cyl_max) 
		{
			if (add_intersection_sorted(head, new_intersection(t, shape)) == ERROR)
				return (ERROR);
		}
		t = (-b + sqrtf(discriminant)) / (2 * a);
		y = ray.origin.y + t * ray.direction.y;
		if (y > shape->cyl_min && y < shape->cyl_max) 
		{
			if (add_intersection_sorted(head, new_intersection(t, shape)) == ERROR)
				return (ERROR);
		}
	}
	// Check for intersections with caps
	if (intersect_caps(head, shape, ray) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int intersect_cylinder(t_intersection **head, t_ray ray, t_object *cylinder) 
{
	float 	a;
	float	b;
	float	c;

	// Body intersection calculations
	a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = powf(ray.origin.x, 2) + powf(ray.origin.z, 2) - 1;
	if (cyl_cone_algorythm(head, ray, cylinder, a, b, c) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	intersect_cone(t_intersection **head, t_ray ray, t_object *cone)
{
	float	a;
	float	b;
	float	c;
	float	t;

	a = powf(ray.direction.x, 2) - powf(ray.direction.y, 2) + powf(ray.direction.z, 2);
	b = 2 * ray.origin.x * ray.direction.x - 2 * ray.origin.y * ray.direction.y + 2 * ray.origin.z * ray.direction.z;
	c = powf(ray.origin.x, 2) - powf(ray.origin.y, 2) + powf(ray.origin.z, 2);
	if (equal_float(a, 0))
	{
		if (equal_float(b, 0))
			return (SUCCESS);
		t = -c / 2 * b;
		if (add_intersection_sorted(head, new_intersection(t, cone)) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (cyl_cone_algorythm(head, ray, cone, a, b, c) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	intersect_sphere(t_intersection **head, t_ray ray, t_object *sphere)
{
	t_tuple			sphere_to_ray;
	float			discriminant;
	float			t;
	float			a;
	float			b;
	float			c;

	sphere_to_ray = subtract_tuple(ray.origin, sphere->center);
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	c = get_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = get_discriminant(a, b, c);
	if (discriminant < 0)
		return (SUCCESS);
	t = (-b - sqrtf(discriminant)) / (2 * a);
	if (add_intersection_sorted(head, new_intersection(t, sphere)) == ERROR)
		return (ERROR);
	t = (-b + sqrtf(discriminant)) / (2 * a);
	if (add_intersection_sorted(head, new_intersection(t, sphere)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	local_intersect(t_intersection **head, t_object *shape, t_ray ray)
{
	if (shape->base->type == SPHERE)
	{
		if (intersect_sphere(head, ray, shape) == ERROR)
			return (ERROR);
	}
	else if (shape->base->type == PLANE)
	{
		if (intersect_plane(head, ray, shape) == ERROR)
			return (ERROR);
	}
	else if (shape->base->type == CYLINDER)
	{
		if (intersect_cylinder(head, ray, shape) == ERROR)
			return (ERROR);
	}
	else if (shape->base->type == CONE)
	{
		if (intersect_cone(head, ray, shape) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	intersect(t_intersection **head, t_object *shape, t_ray ray)
{
	if (!is_identity_matrix(shape->base->transformation.grid, 4))
		ray = transform_ray(ray, *shape->base->inverted);
	if (local_intersect(head, shape, ray) == ERROR)
		return (ERROR);
	return(SUCCESS);
}

t_intersection *intersect_world(t_world *world, t_ray ray)
{
	t_object *cur;
	t_intersection	*list;

	list = NULL;
	cur = world->shapes;
	while (cur)
	{
		if (intersect(&list, cur, ray) == ERROR)
			return (NULL);
		cur = cur->next;
	}
	return (list);
}