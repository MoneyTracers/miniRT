/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:51:48 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/02 12:26:08 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "tuples.h"
# include "matrix.h"
# include "color.h"


typedef enum
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
} t_object_type;

typedef struct s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
	float	reflective;
}	t_material;

typedef	struct	s_object_base
{
	int						type;
	t_matrix				transformation;
	t_matrix				*inverted;
	struct s_object_base	*next;
}	t_object_base;

typedef struct	s_object
{
	int				type;
	t_tuple			center;
	float			radius;
	float			cyl_min;
	float			cyl_max;
	bool			cyl_capped;
	t_tuple			plane_normal;
	t_material		material;
	t_object_base	*base;
	struct s_object	*next;
}	t_object;

t_object		*new_object(t_tuple center, float radius, t_material material, t_object_base *base);
t_object_base	*new_object_base(int type, t_matrix transformation);
t_material		default_material(void);

#endif