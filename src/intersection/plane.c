/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:43:58 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 17:04:02 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <list.h>

int	intersect_plane(t_intersect **head, t_ray ray, t_object *object)
{
	float	t;
	float	denominator;

	denominator = get_dot_product(object->plane->normal, ray.direction);
	if (ft_fabs(denominator) < EPSILON)
		return (SUCCESS);
	t = get_dot_product(object->plane->normal, \
		subtract_tuple(create_point(0, 0, 0), ray.origin)) / denominator;
	if (add_intersect_sorted(head, new_intersect(t, object)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
