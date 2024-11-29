/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 14:39:19 by marieke           #+#    #+#             */
/*   Updated: 2024/11/29 17:03:20 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <transformation.h>
#include <free.h>

float	get_discriminant(float a, float b, float c)
{
	float	discriminant;

	discriminant = powf(b, 2) - 4 * a * c;
	return (discriminant);
}

int	local_intersect(t_intersect **head, t_object *object, t_ray ray)
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

int	intersect(t_intersect **head, t_object *object, t_ray ray)
{
	if (!is_identity_matrix(object->transformation, 4))
	{
		ray = transform_ray(ray, object->inverted);
		if (isnan(ray.origin.x) || isnan(ray.direction.x))
			return (SUCCESS); //MIGHT BE DELETED
	}
	if (local_intersect(head, object, ray) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

t_intersect	*intersect_world(t_world *world, t_ray ray)
{
	t_object		*cur;
	t_intersect	*list;

	list = NULL;
	cur = world->objects;
	while (cur)
	{
		if (intersect(&list, cur, ray) == ERROR)
		{
			free_intersection(&list);
			return (NULL); //need error value here
		}
		cur = cur->next;
	}
	return (list);
}
