/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_elements.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:32:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/06 16:41:57 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

  
#include <minirt.h>
#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

void	parse_add_sphere(t_world *world, char *str)
{
	int	i;
	t_sphere *sphere;
	t_transformation	transform;
	t_tuple coor;
	float	diameter;
	t_material	m;

	i = 0;
	coor = parse_get_coordinates(str, &i);
	diameter = parse_get_float(str, &i);
	m = default_material();
	m.color = parse_get_color(str, &i);
	sphere = new_sphere();
	transform.rotate = create_identity_matrix();
	transform.scale = scale_matrix(diameter / 10, diameter / 10, diameter / 10);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	add_object_to_list(&world->objects, new_object(SPHERE, m, transformation_matrix(transform), (void *)sphere));
	free_transformation_matrix(&transform);
	return ;
}
void	parse_add_plane(t_world *world, char *str)
{
	int	i;
	t_plane *plane;
	t_transformation	transform;
	t_tuple coor;
	t_tuple normal_vec;
	t_material	m;

	i = 0;
	coor = parse_get_coordinates(str, &i);
	normal_vec = parse_get_coordinates(str, &i);
	m = default_material();
	m.color = parse_get_color(str, &i);
	// TODO:translate normal_vec to radians
	plane = new_plane(normal_vec);
	transform.rotate = create_identity_matrix();
	transform.scale = create_identity_matrix();
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	add_object_to_list(&world->objects, new_object(PLANE, m, transformation_matrix(transform), (void *)plane));
	free_transformation_matrix(&transform);
	return ;
}
void	parse_add_cyl(t_world *world, char *str)
{
	t_cylinder *cyl;
	t_transformation	transform;
	t_material	m;
	float 	diameter;
	float 	height;
	int	i;
	t_tuple coor;
	t_tuple normal_vec;

	i = 0;
	coor = parse_get_coordinates(str, &i);
	normal_vec = parse_get_coordinates(str, &i);
	diameter = parse_get_float(str, &i);
	height = parse_get_float(str, &i);
	m = default_material();
	m.color = parse_get_color(str, &i);
	cyl = new_cylinder(0, height, true);
	// TODO:translate normal_vec to radians
	transform.rotate = create_identity_matrix();
	transform.scale = scale_matrix(diameter / 10, diameter / 10, diameter / 10);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	add_object_to_list(&world->objects, new_object(CYLINDER, m, transformation_matrix(transform), (void *)cyl));
	free_transformation_matrix(&transform);
	return ;
}
