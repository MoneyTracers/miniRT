/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:51:06 by maraasve          #+#    #+#             */
/*   Updated: 2024/12/02 16:27:47 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <reflection.h>

t_comps	prepare_comps(t_intersect *intersection, t_ray ray)
{
	t_comps	comps;
	t_tuple	over_point;

	comps.t = intersection->t;
	comps.object = intersection->object;
	comps.point = position(ray, comps.t);
	comps.eyev = negate_vector(ray.direction);
	comps.normalv = normal_at(comps.object, comps.point);
	comps.reflectv = reflect(ray.direction, comps.normalv);
	over_point = add_tuple(comps.point, scale_tuple(comps.normalv, EPSILON));
	comps.over_point = over_point;
	comps.shadow = false;
	if (get_dot_product(comps.normalv, comps.eyev) < 0)
		comps.normalv = negate_vector(comps.normalv);
	return (comps);
}
