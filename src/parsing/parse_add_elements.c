/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_elements.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:32:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/27 16:00:29 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

void	parse_add_sphere(t_world *world, char *str)
{
	t_sphere_parse	parse;

	parse.i = 0;
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.diameter = parse_get_float(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	parse.transform.rotate = create_identity_matrix();
	parse.transform.scale = scale_matrix(parse.diameter, parse.diameter, \
	parse.diameter);
	parse.transform.translation = translation_matrix(parse.coor.x, \
	parse.coor.y, parse.coor.z);
	add_object_to_list(&world->objects, new_object(SPHERE, parse.m, \
	transformation_matrix(parse.transform), (void *)new_sphere()));
	return ;
}

t_transformation	get_transform_plane(t_tuple coor)
{
	t_transformation	transform;

	transform.rotate = create_identity_matrix();
	transform.scale = create_identity_matrix();
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	return (transform);
}

void	parse_add_plane(t_world *world, char *str)
{
	t_plane_parse	parse;

	parse.i = 0;
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.normal_vec = parse_get_normal(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	add_object_to_list(&world->objects, new_object(PLANE, parse.m, \
	transformation_matrix(get_transform_plane(parse.coor)), \
	(void *)new_plane(parse.normal_vec)));
	return ;
}

t_transformation	get_transform_cyl(t_tuple coor, t_tuple normal, float dia)
{
	t_transformation	transform;

	transform.rotate = rotation_matrix_from_normal(normal);
	transform.scale = scale_matrix(dia, dia, dia);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	return (transform);
}

void	parse_add_cyl(t_world *world, char *str)
{
	t_cyl_parse	parse;

	parse.i = 0;
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.normal = parse_get_normal(str, &parse.i);
	parse.diameter = parse_get_float(str, &parse.i);
	parse.height = parse_get_float(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	add_object_to_list(&world->objects, \
	new_object(CYLINDER, parse.m, transformation_matrix(\
	get_transform_cyl(parse.coor, \
	parse.normal, parse.diameter)), \
	(void *)new_cylinder(-parse.height / 2, parse.height / 2, true)));
	return ;
}
