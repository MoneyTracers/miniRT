/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:39:19 by marieke           #+#    #+#             */
/*   Updated: 2024/11/06 13:53:54 by maraasve         ###   ########.fr       */
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

int	intersect_plane(t_intersection **head, t_ray ray, t_object *object)
{
	t_tuple	plane_pos;
	float	t;
	float	denominator;

	denominator = get_dot_product(object->plane->normal, ray.direction);
	if (ft_fabs(denominator) < EPSILON)
		return (SUCCESS);
	plane_pos = multiply_matrix_tuple(object->transformation, create_point(0, 0, 0));
	t = get_dot_product(object->plane->normal, subtract_tuple(plane_pos, ray.origin)) / denominator;
	if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
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

bool intersect_caps(t_intersection **head, t_object *object, t_ray ray) 
{
	float	t;
	float	radius;

	if (!object->cylinder->capped || equal_float(ray.direction.y, 0))
		return (SUCCESS);
	radius = 1;
	if (object->type == CONE)
		radius = fabs(object->cylinder->min);
	t = (object->cylinder->min - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, radius))
	{
		if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
			return (ERROR);
	}
	if (object->type == CONE)
		radius = fabs(object->cylinder->max);
	t = (object->cylinder->max - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, radius))
	{
		if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	cyl_cone_algorithm(t_intersection **head, t_ray ray, t_object *object, float a, float b, float c)
{
	float	discriminant;
	float	t;
	float	y;

	discriminant = get_discriminant(a, b, c);
	if (discriminant >= 0)
	{
		t = (-b - sqrtf(discriminant)) / (2 * a);
		y = ray.origin.y + t * ray.direction.y;
		if (y > object->cylinder->min && y < object->cylinder->max) //what to do with this
		{
			if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
				return (ERROR);
		}
		t = (-b + sqrtf(discriminant)) / (2 * a);
		y = ray.origin.y + t * ray.direction.y;
		if (y > object->cylinder->min && y < object->cylinder->max)
		{
			if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
				return (ERROR);
		}
	}
	if (intersect_caps(head, object, ray) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int intersect_cylinder(t_intersection **head, t_ray ray, t_object *object) 
{
	float 	a;
	float	b;
	float	c;

	a = powf(ray.direction.x, 2) + powf(ray.direction.z, 2);
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = powf(ray.origin.x, 2) + powf(ray.origin.z, 2) - 1;
	if (cyl_cone_algorithm(head, ray, object, a, b, c) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	intersect_cone(t_intersection **head, t_ray ray, t_object *object)
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
		if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
			return (ERROR);
		return (SUCCESS);
	}
	if (cyl_cone_algorithm(head, ray, object, a, b, c) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	intersect_sphere(t_intersection **head, t_ray ray, t_object *object)
{
	t_tuple			sphere_to_ray;
	float			discriminant;
	float			t;
	float			a;
	float			b;
	float			c;

	sphere_to_ray = subtract_tuple(ray.origin, object->sphere->center);
	a = get_dot_product(ray.direction, ray.direction);
	b = 2 * get_dot_product(ray.direction, sphere_to_ray);
	c = get_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = get_discriminant(a, b, c);
	if (discriminant < 0)
		return (SUCCESS);
	t = (-b - sqrtf(discriminant)) / (2 * a);
	if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
		return (ERROR);
	t = (-b + sqrtf(discriminant)) / (2 * a);
	if (add_intersection_sorted(head, new_intersection(t, object)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	local_intersect(t_intersection **head, t_object *object, t_ray ray)
{
	if (object->type == SPHERE)
	{
		if (intersect_sphere(head, ray, object) == ERROR)
			return (ERROR);
	}
	else if (object->type == PLANE)
	{
		if (intersect_plane(head, ray, object) == ERROR)
			return (ERROR);
	}
	else if (object->type == CYLINDER)
	{
		if (intersect_cylinder(head, ray, object) == ERROR)
			return (ERROR);
	}
	else if (object->type == CONE)
	{
		if (intersect_cone(head, ray, object) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	intersect(t_intersection **head, t_object *object, t_ray ray)
{
	if (!is_identity_matrix(object->transformation.grid, 4))
		ray = transform_ray(ray, *object->inverted);
	if (local_intersect(head, object, ray) == ERROR)
		return (ERROR);
	return(SUCCESS);
}

t_intersection *intersect_world(t_world *world, t_ray ray)
{
	t_object		*cur;
	t_intersection	*list;

	list = NULL;
	cur = world->objects;
	while (cur)
	{
		if (intersect(&list, cur, ray) == ERROR)
			return (NULL);
		cur = cur->next;
	}
	return (list);
}