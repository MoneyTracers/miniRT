/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:09:43 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/29 16:16:38 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

bool	is_shadowed(t_world *world, t_light light, t_tuple point)
{
	float	distance;
	t_tuple	vector;
	t_ray	shadow_ray;
	t_intersection *hit;

	vector = subtract_tuple(light.pos, point);
	distance = get_magnitude(vector);
	shadow_ray.origin = point;
	shadow_ray.direction = normalize(vector);
	world->shadow_intersections = intersect_world(world, shadow_ray); // can also use local intersections list instead of putting this in the struct
	hit = get_hit(world->shadow_intersections);
	if (!hit)
		return (false);
	if (hit && hit->t < distance)
		return (true);
	return (false);
}
