/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:17:54 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/27 15:31:17 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <reflection.h>
#include <intersection.h>

t_color	reflected_color(t_world *world, t_comps comps, int *remaining)
{
	t_ray	reflect_ray;
	t_color	color;

	if (!comps.object->material.reflective || !(*remaining))
		return (new_color(0, 0, 0));
	reflect_ray.origin = comps.over_point;
	reflect_ray.direction = comps.reflectv;
	(*remaining)--;
	color = color_at(world, reflect_ray, remaining);
	return (colors_multi_scalar(color, comps.object->material.reflective));
}
