/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:37:18 by marieke           #+#    #+#             */
/*   Updated: 2024/10/29 17:53:55 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_intersection	*get_hit(t_intersection *intersections)
{
	t_intersection	*cur;

	cur = intersections;
	while (cur)
	{
		if (cur->t > 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static t_color	shade_hit(t_world *world, t_comps comps)
{
	t_object	*shape;
	t_light		*cur;
	t_color		total_color;
	bool		shadow = false;

	shape = comps.object;
	total_color = new_color(0, 0, 0);
	cur = world->lights;
	while (cur)
	{
		shadow = is_shadowed(world, *cur, comps.over_point);
		total_color = add_colors(total_color, lighting(world, *cur, shape->material, comps.over_point, comps.eyev, comps.normalv, shadow));
		cur = cur->next;
	}
	return (clamp_color(total_color));
}

t_color	color_at(t_world *world, t_intersection *tmp_intersections, t_ray ray)
{
	t_comps	comps;
	t_intersection *hit;

	world->intersections = intersect_world(world, ray);
	hit = get_hit(world->intersections);
	if (!hit)
		return (clamp_color(new_color(0, 0, 0)));
	comps = prepare_comps(hit, ray);
	return (shade_hit(world, comps));
}