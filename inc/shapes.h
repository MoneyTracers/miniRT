/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:51:48 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/06 13:26:25 by maraasve         ###   ########.fr       */
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
} e_object_type;

typedef struct s_material
{
	t_color	color;
	float	ambient;
	float	diffuse;
	float	specular;
	float	shininess;
	float	reflective;
}	t_material;

// typedef	struct	s_object_base
// {
// 	t_matrix				transformation;
// 	t_matrix				*inverted;
// 	t_material				material;
// }	t_object_base;

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
	t_matrix		*inverted;
	t_material		material;
	union
	{
		t_cylinder	*cylinder;
		t_sphere	*sphere;
		t_plane		*plane;
	};
	struct s_object	*next;
}	t_object;

// typedef struct s_triangle
// {
// 	t_tuple	p1;
// 	t_tuple	p2;
// 	t_tuple	p3;
// }	t_triangle;

// t_object		*new_object(t_tuple center, float radius, t_material material, t_object_base *base);
// t_object_base	*new_object_base(int type, t_matrix transformation);

t_material	default_material(void);
t_object	*new_object(int type, t_material m, t_matrix transform, void *shape);
void		add_object_to_list(t_object **head, t_object *new);

t_sphere	*new_sphere(void);
t_cylinder	*new_cylinder(float min, float max, bool capped);
t_plane		*new_plane(t_tuple normal);

#endif