/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:43:58 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:31:19 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <list.h>

int	intersect_plane(t_intersect **head, t_ray ray, t_object *object)
{
	t_tuple	plane_pos;
	float	t;
	float	denominator;

	denominator = get_dot_product(object->plane->normal, ray.direction);
	if (ft_fabs(denominator) < EPSILON)
		return (SUCCESS);
	plane_pos = multiply_matrix_tuple(object->transformation, \
				create_point(0, 0, 0));
	t = get_dot_product(object->plane->normal, \
		subtract_tuple(plane_pos, ray.origin)) / denominator;
	if (add_intersect_sorted(head, new_intersect(t, object)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
