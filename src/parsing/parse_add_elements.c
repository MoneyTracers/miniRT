/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_elements.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:32:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/11/26 17:16:37 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

void	parse_add_sphere(t_world *world, char *str)
{
	int					i;
	t_transformation	transform;
	t_tuple				coor;
	float				diameter;
	t_material			m;

	i = 0;
	coor = parse_get_coordinates(str, &i);
	diameter = parse_get_float(str, &i);
	m = default_material();
	m.color = parse_get_color(str, &i);
	transform.rotate = create_identity_matrix();
	transform.scale = scale_matrix(diameter, diameter, diameter);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	add_object_to_list(&world->objects, new_object(SPHERE, m, transformation_matrix(transform), (void *)sphere));
	return ;
}

// TODO:translate normal_vec to radians
void	parse_add_plane(t_world *world, char *str)
{
	int					i;
	t_transformation	transform;
	t_tuple				coor;
	t_tuple				normal_vec;
	t_material			m;

	i = 0;
	coor = parse_get_coordinates(str, &i);
	normal_vec = parse_get_normal(str, &i);
	m = default_material();
	m.color = parse_get_color(str, &i);
	transform.rotate = create_identity_matrix();
	transform.scale = create_identity_matrix();
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	add_object_to_list(&world->objects, new_object(PLANE, m, transformation_matrix(transform), (void *)plane));
	return ;
}

// t_matrix	get_rotation(t_tuple from, t_tuple to)
// {
// 	t_matrix	rotation;
// 	t_tuple		axis;
// 	float		angle;
	
// 	axis = get_cross_product(from, to);
// 	angle = acosf(get_dot_product(from, to));

// 	rotation_matrix
// }

void	parse_add_cyl(t_world *world, char *str)
{
	t_transformation	transform;
	t_cylinder			*cyl;
	t_material			m;
	float				diameter;
	float				height;
	int					i;
	t_tuple				coor;
	t_tuple				normal_vec;

	i = 0;
	coor = parse_get_coordinates(str, &i);
	normal_vec = parse_get_normal(str, &i);
	(void)normal_vec;
	diameter = parse_get_float(str, &i);
	height = parse_get_float(str, &i);
	m = default_material();
	m.color = parse_get_color(str, &i);
	cyl = new_cylinder(-height / 2, height / 2, true);
	transform.rotate = rotation_matrix_from_normal(normal_vec);
	transform.scale = scale_matrix(diameter, diameter, diameter);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	add_object_to_list(&world->objects, new_object(CYLINDER, m, transformation_matrix(transform), (void *)cyl));
	return ;
}
