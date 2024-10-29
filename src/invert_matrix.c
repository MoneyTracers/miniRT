/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invert_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 12:50:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/10/25 14:34:39 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

float	**allocate_mem_matrix(int size)
{
	float	**new;
	int		i;

	new = malloc(sizeof(float *) * size);
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
	{
		new[i] = malloc(sizeof(float) * size);
		if (!new)
		{
			free_matrix(new, i);
			return (NULL);
		}
		i++;
	}
	return (new);
}

float	**submatrix(float **grid, int row, int col, int size)
{
	float	**sub;
	int		i;
	int		j;
	int		new_row;
	int		new_col;

	sub = allocate_mem_matrix(size - 1);
	if (!sub)
		return (NULL);
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
				sub[new_row][new_col++] = grid[i][j];
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

float	minor(float **grid, int row, int col, int size)
{
	float	**sub;
	float	minor_value;
	
	sub = submatrix(grid, row, col, size);
	if (!sub)
		return (0); //need to look at this since result can also be 0
	minor_value = determinant(sub, size - 1);
	free_matrix(sub, size - 1);
	return (minor_value);
}

float	cofactor(float **grid, int row, int col, int size)
{
	float	minor_value;

	minor_value = minor(grid, row, col, size);
	if ((row + col) % 2)
		return (-minor_value);
	return (minor_value);
}

float determinant(float **grid, int size)
{
	float	det;
	int		col;

	det = 0;
	if (size == 2)
		return (grid[0][0] * grid[1][1] - grid[0][1] * grid[1][0]);
	else
	{
		col = 0;
		while (col < size)
		{
			det += grid[0][col] * cofactor(grid, 0, col, size);
			col++;
		}
	}
	return (det);
}

void	print_matrix(float **matrix, int size)
{
	for(int i = 0; i <size; i++)
	{
		for(int j = 0; j <size; j++)
			printf("%f ", matrix[i][j]);
		printf("\n");
	}
}

t_matrix	*invert_matrix(float **matrix, int size)
{
	float		det;
	t_matrix	*inverted;
	float		**grid;
	int			i;
	int			j;
	
	det = determinant(matrix, size);
	if (!det)
		return (NULL); // error handling here is shittttt
	inverted = malloc(sizeof(t_matrix));
	if (!inverted)
		return (NULL);
	grid = allocate_mem_matrix(size);
	if (!grid)
		return (NULL);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			grid[i][j] = cofactor(matrix, j, i, size) / det;
			j++;
		}
		i++;
	}
	inverted->grid = grid;
	return (inverted);
}
