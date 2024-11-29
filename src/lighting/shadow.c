/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:43 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:31:23 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lighting.h>
#include <intersection.h>
#include <free.h>

bool	is_shadowed(t_world *world, t_light light, t_tuple point)
{
	float			distance;
	t_tuple			vector;
	t_ray			shadow_ray;
	t_intersect	*hit;
	t_intersect	*list;

	vector = subtract_tuple(light.pos, point);
	distance = get_magnitude(vector);
	shadow_ray.origin = point;
	shadow_ray.direction = normalize(vector);
	list = NULL;
	list = intersect_world(world, shadow_ray);
	hit = get_hit(list);
	if (!hit)
	{
		free_intersection(&list);
		return (false);
	}
	if (hit && hit->t < distance)
	{
		free_intersection(&list);
		return (true);
	}
	free_intersection(&list);
	return (false);
}
