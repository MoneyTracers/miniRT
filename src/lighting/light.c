/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:19:39 by marieke           #+#    #+#             */
/*   Updated: 2024/11/27 15:24:08 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lighting.h>
#include <calculations.h>

t_tuple	light_vector(t_tuple intersection, t_tuple light_src)
{
	t_tuple	light_vec;

	light_vec = subtract_tuple(light_src, intersection);
	return (light_vec);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	reflectv;
	t_tuple	scaled_normal;
	float	dot;

	dot = get_dot_product(in, normal);
	scaled_normal = scale_vector(normal, 2 * dot);
	reflectv = subtract_tuple(in, scaled_normal);
	return (reflectv);
}

t_color	get_diffuse(bool shadow, t_material m, t_color color, float ld_normal)
{
	t_color	tmp;

	if (ld_normal < 0 || shadow)
		return (new_color(0, 0, 0));
	tmp = colors_multi_scalar(color, m.diffuse);
	return (colors_multi_scalar(tmp, ld_normal));
}

t_color	get_specular(t_light_vars v, t_material m, t_light light, t_comps comps)
{
	float	factor;

	if (v.light_dot_normal < 0 || comps.shadow)
		return (new_color(0, 0, 0));
	v.reflectv = reflect(negate_vector(v.lightv), comps.normalv);
	v.reflect_dot_eye = get_dot_product(v.reflectv, comps.eyev);
	if (v.reflect_dot_eye < 0)
		return (new_color(0, 0, 0));
	v.factor = powf(v.reflect_dot_eye, m.shininess);
	factor = light.brightness * m.specular * v.factor;
	return (colors_multi_scalar(light.color, factor));
}

t_color	lighting(t_world *world, t_light light, t_material m, t_comps comps)
{
	t_light_vars	vars;
	t_color			result;
	t_color			tmp;
	float			factor;

	vars.color = colors_multi_scalar(m.color, light.brightness);
	tmp = colors_multi_scalar(light.color, 1.0 / 255);
	vars.color = colors_multiply(vars.color, tmp);
	vars.lightv = normalize(subtract_tuple(light.pos, comps.over_point));
	factor = world->ambientf * m.ambient / 255.0;
	tmp = colors_multiply(world->ambient, m.color);
	vars.ambient = colors_multi_scalar(tmp, factor);
	vars.light_dot_normal = get_dot_product(vars.lightv, comps.normalv);
	tmp = get_diffuse(comps.shadow, m, vars.color, vars.light_dot_normal);
	vars.diffuse = tmp;
	vars.specular = get_specular(vars, m, light, comps);
	result = add_colors(add_colors(vars.ambient, vars.diffuse), vars.specular);
	result = clamp_color(result);
	return (result);
}
