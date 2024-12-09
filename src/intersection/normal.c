/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   normal.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/23 12:24:15 by marieke       #+#    #+#                 */
/*   Updated: 2024/12/09 13:33:43 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>

t_tuple	cyl_normal(t_object *object, t_tuple local_point)
{
	float	dist;
	float	y;

	dist = powf(local_point.x, 2) + powf(local_point.z, 2);
	if (dist < 1 && local_point.y >= object->cylinder->max - EPSILON)
		return (create_vector(0, 1, 0));
	else if (dist < 1 && local_point.y <= object->cylinder->min + EPSILON)
		return (create_vector(0, -1, 0));
	else if (object->type == CYLINDER)
		return (create_vector(local_point.x, 0, local_point.z));
	else
	{
		y = sqrtf(powf(local_point.x, 2) + powf(local_point.y, 2));
		if (local_point.y < 0)
			y = -y;
		return (create_vector(local_point.x, -y, local_point.z));
	}
}

t_tuple	local_normal_at(t_object *object, t_tuple local_point)
{
	if (object->type == SPHERE)
		return (subtract_tuple(local_point, object->sphere->center));
	else if (object->type == PLANE)
		return (object->plane->normal);
	else if (object->type == CYLINDER)
		return (cyl_normal(object, local_point));
	return (create_vector(0, 0, 0));
}

t_tuple	normal_at(t_object *object, t_tuple point)
{
	t_tuple		local_point;
	t_tuple		local_normal;
	t_tuple		world_normal;
	t_matrix	transposed;

	if (!is_identity_matrix(object->transformation, 4))
	{
		local_point = multiply_matrix_tuple(object->inverted, point);
		local_normal = local_normal_at(object, local_point);
		transposed = transpose_matrix(object->inverted);
		world_normal = multiply_matrix_tuple(transposed, local_normal);
	}
	else
	{
		local_point = point;
		local_normal = local_normal_at(object, local_point);
		transposed = transpose_matrix(create_identity_matrix());
		world_normal = multiply_matrix_tuple(transposed, local_normal);
	}
	world_normal.w = 0;
	world_normal = normalize(world_normal);
	return (world_normal);
}
