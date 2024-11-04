/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_capital.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:31:28 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/04 15:32:25 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <minirt.h>
#include <parse.h>

void	parse_add_ambient(t_world *world, char *str)
{
	int	i;

	i = 0;
	world->ambientf = parse_get_float(str, &i);
	world->ambient = parse_get_color(str, &i);
	return ;
}
void	parse_add_camera(t_world *world, char *str)
{
	int	i;

	i = 0;
	world->cam->coordinates = parse_get_coordinates(str, &i);
	world->cam->norm_vec = parse_get_coordinates(str, &i);
	world->cam->fov = parse_get_float(str, &i);
	return ;
}
void	parse_add_light(t_world *world, char *str)
{
	int i;

	i = 0;
	world->lights->pos = parse_get_coordinates(str, &i);
	world->lights->brightness = parse_get_float(str, &i);
	world->lights->intensity = parse_get_color(str, &i);
	return ;
}
