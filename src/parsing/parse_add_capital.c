/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_capital.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:31:28 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/08 11:14:19 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <parse.h>
#include <list.h>

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
	int	i;

	i = 1;
	world->cam.coordinates = parse_get_coordinates(str, &i);
	world->cam.norm_vec = parse_get_coordinates(str, &i);
	world->cam.fov = parse_get_float(str, &i);
	return ;
}
void	parse_add_light(t_world *world, char *str)
{
	t_tuple pos;
	float brightness;
	t_color color;
	int i;

	i = 1;
	pos = parse_get_coordinates(str, &i);
	brightness = parse_get_float(str, &i);
	color = parse_get_color(str, &i);
	add_light_to_list(&world->lights, new_light(pos, color));
	return ;
}
