/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:48:24 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/19 13:03:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <transformation.h>
#include <free.h>

t_tuple	translate_tuple(t_tuple tuple, float x, float y, float z)
{
	t_tuple	result;

	if (tuple.w == 0)
		return (tuple);
	result.x = tuple.x + x;
	result.y = tuple.y + y;
	result.z = tuple.z + z;
	return (result);
}

t_matrix	translation_matrix(float x, float y, float z)
{
	t_matrix	new;

	new = create_identity_matrix();
	new.grid[0][3] = x;
	new.grid[1][3] = y;
	new.grid[2][3] = z;
	return (new);
}

t_matrix	scale_matrix(float x, float y, float z)
{
	t_matrix	new;

	new = create_identity_matrix();
	new.grid[0][0] = x;
	new.grid[1][1] = y;
	new.grid[2][2] = z;
	return (new);
}

t_matrix	transformation_matrix(t_transformation transform)
{
	t_matrix	transformation;

	transformation = multiply_matrices(transform.translation, transform.rotate);
    transformation = multiply_matrices(transformation, transform.scale);
	return (transformation);
}

