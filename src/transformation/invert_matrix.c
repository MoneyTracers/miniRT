/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:50:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/19 13:03:44 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <free.h>

t_matrix	submatrix(t_matrix matrix, int row, int col, int size)
{
	t_matrix	sub;
	int		i;
	int		j;
	int		new_row;
	int		new_col;

	i = 0;
	new_row = 0;
	new_col = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i != row && j != col)
			{
				sub.grid[new_row][new_col++] = matrix.grid[i][j];
				if (new_col == size - 1)
				{
					new_col = 0;
					new_row++;
				}
			}
			j++;
		}
		i++;
	}
	return (sub);
}

float	minor(t_matrix matrix, int row, int col, int size)
{
	t_matrix	sub;
	float		minor_value;
	
	sub = submatrix(matrix, row, col, size);
	minor_value = determinant(sub, size - 1);
	return (minor_value);
}

float	cofactor(t_matrix matrix, int row, int col, int size)
{
	float	minor_value;

	minor_value = minor(matrix, row, col, size);
	if ((row + col) % 2)
		return (-minor_value);
	return (minor_value);
}

float	determinant(t_matrix matrix, int size)
{
	float	det;
	int		col;

	det = 0;
	if (size == 2)
		return (matrix.grid[0][0] * matrix.grid[1][1] - matrix.grid[0][1] * matrix.grid[1][0]);
	else
	{
		col = 0;
		while (col < size)
		{
			det += matrix.grid[0][col] * cofactor(matrix, 0, col, size);
			col++;
		}
	}
	return (det);
}

void	print_matrix(float **grid, int size)
{
	for(int i = 0; i <size; i++)
	{
		for(int j = 0; j <size; j++)
			printf("%f ", grid[i][j]);
		printf("\n");
	}
}

t_matrix	invert_matrix(t_matrix matrix, int size)
{
	float		det;
	t_matrix	inverted;
	int			i;
	int			j;
	
	det = determinant(matrix, size);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			inverted.grid[i][j] = cofactor(matrix, j, i, size) / det;
			j++;
		}
		i++;
	}
	return (inverted);
}
