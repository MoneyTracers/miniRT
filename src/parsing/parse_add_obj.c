/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_obj.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:32:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/12/03 18:15:27 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

void	parse_add_obj(t_world *world, void *shape, t_matrix mat, t_pobj parse)
{
	t_object		*obj;

	if (!shape)
		set_error(world, 1, OBJECT, NULL);
	obj = new_object(SPHERE, parse.m, mat, shape);
	if (!obj)
	{
		set_error(world, 1, OBJECT, NULL);
		free(shape);
	}
	if (!world->exit_code)
		add_object_to_list(&world->objects, obj);
}
