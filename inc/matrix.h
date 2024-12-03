/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:37:57 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <tuples.h>
# include <stdlib.h>
# define MAX_PITCH 0.7

typedef struct s_matrix
{
	float	grid[4][4];
}	t_matrix;

t_matrix	create_identity_matrix(void);
t_tuple		multiply_matrix_tuple(t_matrix matrix, t_tuple tuple);
t_matrix	multiply_matrices(t_matrix one, t_matrix two);
t_matrix	transpose_matrix(t_matrix matrix);
bool		is_identity_matrix(t_matrix matrix, int size);
t_matrix	submatrix(t_matrix matrix, int row, int col, int size);
float		determinant(t_matrix matrix, int size);
t_matrix	invert_matrix(t_matrix matrix, int size);

#endif