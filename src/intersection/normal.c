/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:24:15 by marieke           #+#    #+#             */
/*   Updated: 2024/11/02 13:15:44 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

t_tuple	local_normal_at(t_object *shape, t_tuple local_point)
{
	float	dist;
	float	y;

	if (shape->base->type == SPHERE)
		return (subtract_tuple(local_point, shape->center));
	else if (shape->base->type == PLANE)
		return (shape->plane_normal);
	else if (shape->base->type == CYLINDER || shape->base->type == CONE)
	{
		dist = powf(local_point.x, 2) + powf(local_point.z, 2);
		if (dist < 1 && local_point.y >= shape->cyl_max - EPSILON)
			return (create_vector(0, 1, 0));
		else if (dist < 1 && local_point.y <= shape->cyl_min + EPSILON)
			return (create_vector(0, -1, 0));
		else if (shape->base->type == CYLINDER)
			return (create_vector(local_point.x, 0, local_point.z));
		else
		{
			y = sqrtf(powf(local_point.x, 2) + powf(local_point.y, 2));
			if (local_point.y < 0)
				y = -y;
			return (create_vector(local_point.x, -y, local_point.z));
		}
	}
	return (create_vector(0, 0, 0));
}

t_tuple	normal_at(t_object *shape, t_tuple point)
{
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;
	
	if (shape->base->inverted)
	{
		local_point = multiply_matrix_tuple(*shape->base->inverted, point);
		local_normal = local_normal_at(shape, local_point);
		world_normal = multiply_matrix_tuple(transpose_matrix(*shape->base->inverted), local_normal);
	}
	else
	{
		local_point = point;
		local_normal = local_normal_at(shape, local_point);
		world_normal = multiply_matrix_tuple(transpose_matrix(create_identity_matrix()), local_normal);
	}
	world_normal.w = 0;
	world_normal = normalize(world_normal);
	return (world_normal);
}
