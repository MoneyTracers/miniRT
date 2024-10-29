/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:17:54 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/29 17:50:44 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_color	reflected_color(t_world *world, t_comps comps)
{
	t_ray	reflect_ray;
	t_color	color;

	if (!comps.object->material.reflective)
		return (new_color(0, 0, 0));
	reflect_ray.origin = comps.over_point;
	reflect_ray.direction = comps.reflectv;
	color = color_at(); // need to refactor the color_at function so i can use it both here and for the hit;
	return (colors_multi_scalar(color, comps.object->material.reflective));
}