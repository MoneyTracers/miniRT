/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_capital.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:31:28 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/26 17:16:44 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parse.h>
#include <list.h>
#include <calculations.h>
#include <camera.h>
#include <free.h>

void	parse_add_ambient(t_world *world, char *str)
{
	int	i;

	i = 1;
	world->ambientf = parse_get_float(str, &i);
	world->ambient = parse_get_color(str, &i);
	return ;
}

void	parse_add_camera(t_world *world, char *str)
{
	t_matrix	view_transform;
	int	i;

	i = 1;
	world->cam.pos = parse_get_coordinates(str, &i);
	world->cam.normal = parse_get_normal(str, &i);
	view_transform = view_transformation(&world->cam, world->cam.pos, world->cam.normal, create_vector(0, 1, 0));
	new_camera(&world->cam, degrees_to_radians(parse_get_float(str, &i)), view_transform);
	return ;
}

void	parse_add_light(t_world *world, char *str)
{
	t_tuple	pos;
	t_color	color;
	float	brightness;
	int 	i;

	i = 1;
	pos = parse_get_coordinates(str, &i);
	brightness = parse_get_float(str, &i);
	color = parse_get_color(str, &i);
	add_light_to_list(&world->lights, new_light(pos, color, brightness));
	return ;
}
