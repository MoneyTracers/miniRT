/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 13:19:39 by marieke           #+#    #+#             */
/*   Updated: 2024/11/06 15:39:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lighting.h>
#include <calculations.h>

t_tuple	light_vector(t_tuple intersection, t_tuple light_src)
{
	t_tuple	light_vec;

	light_vec = subtract_tuple(light_src, intersection);
	return(light_vec);
}

t_tuple	reflect(t_tuple in, t_tuple normal)
{
	t_tuple	reflectv;
	t_tuple	scaled_normal;
	float	dot;

	dot = get_dot_product(in, normal);
	scaled_normal = scale_vector(normal, 2 * dot);
	reflectv = subtract_tuple(in, scaled_normal);
	return(reflectv);
}

t_material	default_material(void)
{
	t_material	material;

	material.color.r = 1;
	material.color.g = 1;
	material.color.b = 1;
	material.ambient = 0.3;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	material.reflective = 0;
	return (material);
}

t_color	lighting(t_world *world, t_light light, t_material m, t_tuple pos, t_tuple eyev, t_tuple normalv, bool in_shadow)
{
	t_color	result;
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	effective_color;
	t_tuple	lightv;
	t_tuple	reflectv;
	float	reflect_dot_eye;
	float	light_dot_normal;
	float	factor;

	effective_color = colors_multi_scalar(m.color, light.intensity);
	effective_color = colors_multiply(effective_color, light.color);
	lightv = normalize(subtract_tuple(light.pos, pos));
	ambient = colors_multi_scalar(colors_multiply(world->ambient, m.color), world->ambientf * m.ambient);
	light_dot_normal = get_dot_product(lightv, normalv);
	if (light_dot_normal < 0 || in_shadow)
	{
		diffuse = new_color(0, 0, 0);
		specular = new_color(0, 0, 0);
	}
	else
	{
		diffuse = colors_multi_scalar(colors_multi_scalar(effective_color, m.diffuse), light_dot_normal);
		reflectv = reflect(negate_vector(lightv), normalv);
		reflect_dot_eye = get_dot_product(reflectv, eyev);
		if (reflect_dot_eye < 0)
			specular = new_color(0, 0, 0);
		else
		{
			factor = powf(reflect_dot_eye, m.shininess);
			specular = colors_multi_scalar(light.color, light.intensity * m.specular * factor);
		}
	}
	result = add_colors(add_colors(ambient, diffuse), specular);
	result = clamp_color(result);
	return (result);
}
