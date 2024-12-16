/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_add_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 14:32:54 by spenning          #+#    #+#             */
/*   Updated: 2024/12/16 14:03:13 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parse.h>
#include <shapes.h>
#include <transformation.h>
#include <free.h>

void	parse_add_sphere(t_world *world, char *str)
{
	t_pobj			parse;
	t_sphere		*sp;

	sp = NULL;
	ft_bzero(&parse, sizeof(parse));
	parse.type = SPHERE;
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.diameter = parse_get_float(str, &parse.i);
	if (parse.diameter <= 0)
		set_error(world, 1, DIAMETER, NULL);
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

	pl = NULL;
	ft_bzero(&parse, sizeof(parse));
	parse.type = PLANE;
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.normal = parse_get_normal(str, &parse.i);
	if (get_magnitude(parse.normal) != 1)
		set_error(world, 1, NORMAL, NULL);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	if (!world->exit_code)
		pl = (void *)new_plane(parse.normal);
	parse_add_obj(world, pl, \
	transformation_matrix(get_transform_plane(parse.coor)), parse);
	return ;
}

void	parse_add_cyl(t_world *world, char *str)
{
	t_pobj			parse;
	t_cylinder		*cyl;

	cyl = NULL;
	ft_bzero(&parse, sizeof(parse));
	parse.type = CYLINDER;
	parse.coor = parse_get_coordinates(str, &parse.i);
	parse.normal = parse_get_normal(str, &parse.i);
	if (get_magnitude(parse.normal) != 1)
		set_error(world, 1, NORMAL, NULL);
	parse.diameter = parse_get_float(str, &parse.i);
	if (parse.diameter <= 0)
		set_error(world, 1, DIAMETER, NULL);
	parse.height = parse_get_float(str, &parse.i);
	parse.m = default_material();
	parse.m.color = parse_get_color(str, &parse.i);
	if (!world->exit_code)
		cyl = (void *)new_cylinder(-parse.height / 2, parse.height / 2, true);
	parse_add_obj(world, cyl, transformation_matrix(\
	get_transform_cyl(parse.coor, parse.normal, parse.diameter)), parse);
	return ;
}
