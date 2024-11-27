/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:48:35 by marieke           #+#    #+#             */
/*   Updated: 2024/11/27 16:04:12 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>
#include <calculations.h>

bool	equal_matrix(t_matrix one, t_matrix two, int rows, int columns)
{
	int	i;
	int	j;

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

t_matrix	create_identity_matrix(void)
{
	t_matrix	identity;
	int			row;
	int			col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
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

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			new.grid[row][col] = matrix.grid[col][row];
			col++;
		}
		row++;
	}
	return (new);
}

bool	is_identity_matrix(t_matrix matrix, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (i == j)
			{
				if (matrix.grid[i][j] != 1.0f)
					return (false);
			}
			else
			{
				if (matrix.grid[i][j] != 0.0f)
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}
