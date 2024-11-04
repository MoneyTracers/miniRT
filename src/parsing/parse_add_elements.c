/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_elements.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:32:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/04 15:11:16 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>
#include <tuples.h>
#include <parse.h>

void	parse_add_sphere(t_world *world, char *str)
{
	int	i;
	t_object **obj;
	t_material mat;
	t_tuple coor;
	t_object_base base;
	float diameter;

	i = 0;
	base.type = SPHERE;
	coor = parse_get_coordinates(str, &i);
	diameter = parse_get_float(str, &i);
	mat.color = parse_get_color(str, &i);
	new_object(coor, diameter * 2, mat, &base);
	return ;
}
void	parse_add_plane(t_world *world, char *str)
{
	int	i;
	t_object **obj;
	t_material mat;
	t_tuple coor;
	t_object_base base;

	i = 0;
	base.type = CYLINDER;
	coor = parse_get_coordinates(str, &i);
	//TODO: add normal vec
	mat.color = parse_get_color(str, &i);
	new_object(coor, 0, mat, &base);
	return ;
}
void	parse_add_cyl(t_world *world, char *str)
{
	int	i;
	t_object **obj;
	t_material mat;
	t_tuple coor;
	t_object_base base;
	float diameter;

	i = 0;
	base.type = CYLINDER;
	coor = parse_get_coordinates(str, &i);
	//TODO:add normal vec of axis
	diameter = parse_get_float(str, &i);
	//TODO:add height
	mat.color = parse_get_color(str, &i);
	new_object(coor, diameter * 2, mat, &base);
	return ;
}
