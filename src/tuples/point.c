/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   point.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 13:17:37 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/04 15:24:19 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

bool	is_point(t_tuple tuple)
{
	if (tuple.w == 1.0)
		return (true);
	return (false);
}

t_tuple	create_point(float x, float y, float z)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 1.0;
	return (new);
}
