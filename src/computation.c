/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:53:11 by marieke           #+#    #+#             */
/*   Updated: 2024/10/23 14:28:35 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_comps	*prepare_computations(t_intersection *intersection, t_ray ray)
{
	t_comps *new;

	new = malloc(sizeof(t_comps));
	if (!new)
		return (NULL);
	new->t = intersection->t;
	new->object = intersection->object;
	new->point = position(ray, intersection->t);
	new->eyev = negate_vector(ray.direction);
	new->normalv = normal_at(new->object, new->point);
	if (get_dot_product(new->normalv, new->eyev) < 0)
		new->inside = true;
	else
		new->inside = false;
	return (new);
}