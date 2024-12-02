/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:43 by maraasve          #+#    #+#             */
/*   Updated: 2024/12/02 16:47:11 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lighting.h>
#include <intersection.h>
#include <free.h>

bool	shadow_hit(t_intersect *list, float distance, t_ray shadow_ray)
{
	t_intersect	*hit;
	float		dot;

	hit = get_hit(list);
	if (!hit)
		return (false);
	if (hit && hit->t < distance)
	{
		if (hit->object->type == PLANE)
		{
			dot = get_dot_product(hit->object->plane->normal, \
									shadow_ray.direction);
			if (dot <= 0)
				return (false);
		}
		return (true);
	}
	return (false);
}

bool	is_shadowed(t_world *world, t_light light, t_tuple point)
{
	float			distance;
	t_tuple			vector;
	t_ray			shadow_ray;
	t_intersect		*list;

	vector = subtract_tuple(light.pos, point);
	distance = get_magnitude(vector);
	shadow_ray.origin = point;
	shadow_ray.direction = normalize(vector);
	list = NULL;
	list = intersect_world(world, shadow_ray);
	if (shadow_hit(list, distance, shadow_ray))
	{
		free_intersection(&list);
		return (true);
	}
	free_intersection(&list);
	return (false);
}
