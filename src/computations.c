/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:06 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/25 14:13:27 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_comps	prepare_comps(t_intersection *intersection, t_ray ray)
{
	t_comps	comps;

	comps.t = intersection->t;
	comps.object = intersection->object;
	comps.point = position(ray, comps.t);
	comps.eyev = negate_vector(ray.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	//comps.over_point = add_tuple(comps.point, scale_tuple(comps.normalv, EPSILON));
	if (get_dot_product(comps.normalv, comps.eyev) < 0)
	{
		comps.inside = true;
		comps.normalv = negate_vector(comps.normalv);
	}
	else
		comps.inside = false;
	return (comps);
}