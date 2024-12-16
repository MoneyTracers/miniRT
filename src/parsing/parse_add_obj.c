/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:32:54 by spenning          #+#    #+#             */
/*   Updated: 2024/12/16 16:00:57 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

void	parse_add_obj(t_world *world, void *shape, t_matrix mat, t_pobj parse)
{
	t_object		*obj;

	world->obj_count++;
	if (world->obj_count > 999)
	{
		set_error(world, 1, OBJECT_COUNT, NULL);
		return ;
	}
	if (world->exit_code)
		return ;
	if (!shape)
	{
		set_error(world, 1, OBJECT, NULL);
		return ;
	}
	obj = new_object(parse.type, parse.m, mat, shape);
	if (!obj)
	{
		set_error(world, 1, OBJECT, NULL);
		free(shape);
	}
	if (!world->exit_code)
		add_object_to_list(&world->objects, obj);
}
