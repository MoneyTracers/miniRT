/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:45 by marieke           #+#    #+#             */
/*   Updated: 2024/10/25 15:41:48 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_matrix	rotate_x(float radians)
{
	t_matrix	rotation;

	rotation = create_identity_matrix();
	rotation.grid[1][1] = cosf(radians);
	rotation.grid[1][2] = -sinf(radians);
	rotation.grid[2][1] = sinf(radians);
	rotation.grid[2][2] = cosf(radians);
	return (rotation);
}

t_matrix	rotate_y(float radians)
{
	t_matrix	rotation;

	rotation = create_identity_matrix();
	rotation.grid[0][0] = cosf(radians);
	rotation.grid[0][2] = sinf(radians);
	rotation.grid[2][0] = -sinf(radians);
	rotation.grid[2][2] = cosf(radians);
	return (rotation);
}

t_matrix	rotate_z(float radians)
{
	t_matrix	rotation;

	rotation = create_identity_matrix();
	rotation.grid[0][0] = cosf(radians);
	rotation.grid[0][1] = -sinf(radians);
	rotation.grid[1][0] = sinf(radians);
	rotation.grid[1][1] = cosf(radians);
	return (rotation);
}

t_matrix	rotate(float x, float y, float z)
{
	t_matrix	rotatex;
	t_matrix	rotatey;
	t_matrix	rotatez;
	t_matrix	rotation;

	if (x)
		rotatex = rotate_x(x);
	else
		rotatex = create_identity_matrix();
	if (y)
		rotatey = rotate_y(y);
	else
		rotatey = create_identity_matrix();
	if (z)
		rotatez = rotate_z(z);
	else
		rotatez = create_identity_matrix();
	rotation = multiply_matrices(rotatez, rotatey);
	rotation = multiply_matrices(rotation, rotatex);
	free_matrix(rotatex.grid, 4);
	free_matrix(rotatey.grid, 4);
	free_matrix(rotatez.grid, 4);
	return (rotation);
}

// t_tuple	shearing(t_tuple point, ....)
// {
// 	t_tuple		new_point;
// 	t_matrix	shear_matrix;

// 	shear_matrix = create_identity_matrix();
	
// } not sure if we'll need this