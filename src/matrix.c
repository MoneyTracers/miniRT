/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:48:35 by marieke           #+#    #+#             */
/*   Updated: 2024/10/25 15:40:53 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float **create_matrix(int rows, int columns)
{
	float	**matrix;
	int		i;

	matrix = malloc(sizeof(float *) * rows);
	if (!matrix)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		matrix[i] = malloc(sizeof(float) * columns);
		if (!matrix[i])
		{
			free_matrix(matrix, i);
			return (NULL);
		}
		i++;
	}
	return (matrix);
}

bool	equal_matrix(t_matrix one, t_matrix two, int rows, int columns)
{
	int i;
	int j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (!equal_float(one.grid[i][j], two.grid[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_matrix	multiply_matrices(t_matrix one, t_matrix two)
{
	t_matrix new;
	int	row;
	int	col;
	int k;

	row = 0;
	new = create_identity_matrix();
	//ERROR HANDLING
	while (row < MS)
	{
		col = 0;
		while (col < MS)
		{
			new.grid[row][col] = 0;
			col++;
		}
		row++;
	}
	row = 0;
	while (row < MS)
	{
		col = 0;
		while (col < MS)
		{
			k = 0;
			while (k < MS)
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

t_matrix	create_identity_matrix(void)
{
	t_matrix	identity;
	int row;
	int col;
	
	identity.grid = allocate_mem_matrix(4);
	if (!identity.grid)
		return(identity); //not sure about this error handling
	row = 0;
	while (row < MS)
	{
		col = 0;
		while (col < MS)
		{
			if (col == row)
				identity.grid[row][col] = 1;
			else
				identity.grid[row][col] = 0;
			col++;
		}
		row++;
	}
	return (identity);
}

t_matrix	transpose_matrix(t_matrix matrix)
{
	t_matrix	new;
	int			row;
	int			col;

	new.grid = create_matrix(MS, MS); //better to use matrix.size
	if (!new.grid)
		return (create_identity_matrix()); //need better error handling
	row = 0;
	while (row < MS)
	{
		col = 0;
		while (col < MS)
		{
			new.grid[row][col] = matrix.grid[col][row];
			col++;
		}
		row++;
	}
	return (new);
}

bool is_identity_matrix(float **matrix, int size) 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				if (matrix[i][j] != 1.0f) {
					return false;
				}
			} else {
				if (matrix[i][j] != 0.0f) {
					return false;
				}
			}
		}
	}
	return true;
}
