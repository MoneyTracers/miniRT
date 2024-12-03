/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiply_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:47:20 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/27 16:30:24 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	multiply_matrices(t_matrix one, t_matrix two)
{
	t_matrix	new;
	int			row;
	int			col;
	int			k;

	row = 0;
	new = create_identity_matrix();
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			k = 0;
			new.grid[row][col] = 0;
			while (k < 4)
			{
				new.grid[row][col] += one.grid[row][k] * two.grid[k][col];
				k++;
			}
			col++;
		}
		row++;
	}
	return (new);
}

float	multiply_row(float row[4], t_tuple tuple)
{
	float	result;

	result = 0;
	result += row[0] * tuple.x;
	result += row[1] * tuple.y;
	result += row[2] * tuple.z;
	result += row[3] * tuple.w;
	return (result);
}

t_tuple	multiply_matrix_tuple(t_matrix matrix, t_tuple tuple)
{
	t_tuple	new;

	new.x = multiply_row(matrix.grid[0], tuple);
	new.y = multiply_row(matrix.grid[1], tuple);
	new.z = multiply_row(matrix.grid[2], tuple);
	new.w = multiply_row(matrix.grid[3], tuple);
	return (new);
}
