/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:36:39 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/27 15:24:12 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "color.h"
# include <tuples.h>
# include <minirt.h>
# include <stdbool.h>
# include <intersection.h>

typedef struct s_light_vars
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	color;
	t_tuple	lightv;
	t_tuple	reflectv;
	float	reflect_dot_eye;
	float	light_dot_normal;
	float	factor;
}	t_light_vars;

bool		is_shadowed(t_world *world, t_light light, t_tuple point);
t_tuple		light_vector(t_tuple intersection, t_tuple light_src);
t_color		lighting(t_world *world, t_light light, t_material m, t_comps comps);
t_light		*new_light(t_tuple pos, t_color color, float brightness);

#endif