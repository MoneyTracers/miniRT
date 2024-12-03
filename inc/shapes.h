/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:51:48 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:44:08 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
# define SHAPES_H

# include "tuples.h"
# include "matrix.h"
# include "color.h"

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
}	t_object_type;

typedef struct s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
	float	reflective;
}	t_material;

typedef struct s_sphere
{
	t_tuple	center;
	float	radius;
}	t_sphere;

typedef struct s_cylinder
{
	float	min;
	float	max;
	bool	capped;
}	t_cylinder;

typedef struct s_plane
{
	t_tuple	normal;
}	t_plane;

typedef struct s_object
{
	int				type;
	t_matrix		transformation;
	t_matrix		inverted;
	t_material		material;
	union
	{
		t_cylinder	*cylinder;
		t_sphere	*sphere;
		t_plane		*plane;
	};
	struct s_object	*next;
}	t_object;

t_material	default_material(void);
t_object	*new_object(int type, t_material m, t_matrix trnsform, void *shape);
void		add_object_to_list(t_object **head, t_object *new);
t_sphere	*new_sphere(void);
t_cylinder	*new_cylinder(float min, float max, bool capped);
t_plane		*new_plane(t_tuple normal);

#endif