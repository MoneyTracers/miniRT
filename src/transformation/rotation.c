/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 14:25:45 by marieke           #+#    #+#             */
/*   Updated: 2024/11/19 13:04:25 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <transformation.h>
#include <free.h>

t_matrix rotation_matrix_from_normal(t_tuple normal)
{
	t_tuple	up;
	t_tuple	axis;
	float	cos_theta;
	float	theta;

	up = create_vector(0, 1, 0);
	axis = get_cross_product(up, normal);
	if (equal_float(get_magnitude(axis), 0.0))
		return (create_identity_matrix());
	axis = normalize(axis);
	cos_theta = get_dot_product(up, normal);
	theta = acosf(fminf(fmaxf(cos_theta, -1.0f), 1.0f));
	return (rotate(axis.x * theta, axis.y * theta, axis.z * theta));
}

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
	return (rotation);
}
