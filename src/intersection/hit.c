/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:37:18 by marieke           #+#    #+#             */
/*   Updated: 2024/12/02 16:16:55 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <reflection.h>
#include <free.h>
#include <lighting.h>

t_intersect	*get_hit(t_intersect *intersections)
{
	t_intersect	*cur;

	cur = intersections;
	while (cur)
	{
		if (cur->t > 0)
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

static t_color	shade_hit(t_world *world, t_comps comps, int *remaining)
{
	t_object	*shape;
	t_light		*cur;
	t_color		color;
	t_color		light_result;

	shape = comps.object;
	color = new_color(0, 0, 0);
	cur = world->lights;
	while (cur)
	{
		comps.shadow = is_shadowed(world, *cur, comps.over_point);
		light_result = lighting(world, *cur, shape->material, comps);
		color = add_colors(color, light_result);
		cur = cur->next;
	}
	color = add_colors(color, reflected_color(world, comps, remaining));
	return (clamp_color(color));
}

t_color	color_at(t_world *world, t_ray ray, int *remaining)
{
	t_comps			comps;
	t_intersect	*hit;
	t_intersect	*list;

	list = NULL;
	list = intersect_world(world, ray);
	hit = get_hit(list);
	if (!hit)
		return (new_color(0, 0, 0));
	comps = prepare_comps(hit, ray);
	free_intersection(&list);
	return (shade_hit(world, comps, remaining));
}
