/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tuples.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/30 17:07:14 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/19 18:41:03 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include <math.h>
# include <stdbool.h>
# include <stdlib.h>

typedef float				t_fvec \
__attribute__ ((vector_size (4 * sizeof(float))));

typedef struct	s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;

//point.c
bool	is_point(t_tuple tuple);
t_tuple	create_point(float x, float y, float z);

//tuples.c
bool	same_tuple(t_tuple one, t_tuple two);
t_tuple	add_tuple(t_tuple one, t_tuple two);
t_tuple	subtract_tuple(t_tuple one, t_tuple two);
t_tuple	scale_tuple(t_tuple tuple, float factor);

//vector.c
bool	is_vector(t_tuple tuple);
t_tuple	create_vector(float x, float y, float z);
t_tuple	scale_vector(t_tuple vector, float scale);
t_tuple	negate_vector(t_tuple vector);

#endif