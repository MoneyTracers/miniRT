/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:43 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/29 13:26:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	is_shadowed(t_world *world, t_tuple point)
{
	float	distance;
	t_tuple	vector;
	t_ray	shadow_ray;
	t_intersection *hit;

	vector = subtract_tuple(world->light.pos, point);
	distance = get_magnitude(vector);
	shadow_ray.origin = point;
	shadow_ray.direction = normalize(vector);
	world->shadow_intersections = intersect_world(world, shadow_ray);
	hit = get_hit(world->shadow_intersections);
	if (!hit)
		return (false);
	if (hit && hit->t < distance)
		return (true);
	return (false);
}
