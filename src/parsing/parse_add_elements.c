/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_add_elements.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/01 14:32:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/12/03 18:15:01 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

t_transformation	get_transform_plane(t_tuple coor)
{
	t_transformation	transform;

	transform.rotate = create_identity_matrix();
	transform.scale = create_identity_matrix();
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	return (transform);
}

t_transformation	get_transform_cyl(t_tuple coor, t_tuple normal, float dia)
{
	t_transformation	transform;

	transform.rotate = rotation_matrix_from_normal(normal);
	transform.scale = scale_matrix(dia, dia, dia);
	transform.translation = translation_matrix(coor.x, coor.y, coor.z);
	return (transform);
}

void	parse_add_sphere(t_world *world, char *str)
{
	t_pobj			parse;
	t_sphere		*sp;
	t_object		*obj;

	ft_bzero(&parse, sizeof(parse));
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.diameter = parse_get_float(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	parse.transform.rotate = create_identity_matrix();
	parse.transform.scale = scale_matrix(parse.diameter, parse.diameter, \
	parse.diameter);
	parse.transform.translation = translation_matrix(parse.coor.x, \
	parse.coor.y, parse.coor.z);
	sp = (void *)new_sphere();
	parse_add_obj(world, sp, transformation_matrix(parse.transform), parse);
	return ;
}

void	parse_add_plane(t_world *world, char *str)
{
	t_pobj			parse;
	t_plane			*pl;
	t_object		*obj;

	ft_bzero(&parse, sizeof(parse));
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.normal_vec = parse_get_normal(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	pl = (void *)new_plane(parse.normal_vec);
	parse_add_obj(world, pl, \
	transformation_matrix(get_transform_plane(parse.coor)), parse);
	return ;
}

void	parse_add_cyl(t_world *world, char *str)
{
	t_pobj			parse;
	t_cylinder		*cyl;
	t_object		*obj;

	ft_bzero(&parse, sizeof(parse));
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.normal = parse_get_normal(str, &parse.i);
	parse.diameter = parse_get_float(str, &parse.i);
	parse.height = parse_get_float(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	cyl = (void *)new_cylinder(-parse.height / 2, parse.height / 2, true);
	parse_add_obj(world, cyl, transformation_matrix(\
	get_transform_cyl(parse.coor, parse.normal, parse.diameter)), parse);
	return ;
}
