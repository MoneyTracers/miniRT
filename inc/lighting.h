/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lighting.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:36:39 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/12 13:52:01 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHTING_H
# define LIGHTING_H

# include "color.h"
# include <tuples.h>
# include <minirt.h>
# include <stdbool.h>


bool		is_shadowed(t_world *world, t_light light, t_tuple point);
t_tuple		light_vector(t_tuple intersection, t_tuple light_src);
t_light		*new_light(t_tuple pos, t_color color, float brightness);
t_color		lighting(t_world *world, t_light light, t_material m, t_tuple pos, t_tuple eyev, t_tuple normalv, bool in_shadow);

#endif