/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:14 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 17:36:16 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <tuples.h>
# include <calculations.h>
# include <shapes.h>
# include <minirt.h>

typedef enum s_values
{
	A = 0,
	B,
	C
}	t_values;

typedef struct s_intersect
{
	float				t;
	t_object			*object;
	struct s_intersect	*next;
}	t_intersect;

typedef struct s_comps
{
	float		t;
	t_object	*object;
	t_tuple		point;
	t_tuple		over_point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_tuple		reflectv;
	bool		shadow;
}	t_comps;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

t_comps		prepare_comps(t_intersect *intersection, t_ray ray);
t_intersect	*intersect_world(t_world *world, t_ray ray);
t_color		color_at(t_world *world, t_ray ray, int *remaining);
t_intersect	*get_hit(t_intersect *intersections);
t_tuple		position(t_ray ray, float time);
t_tuple		normal_at(t_object *shape, t_tuple point);
float		get_discriminant(float a, float b, float c);
int			intersect_plane(t_intersect **head, t_ray ray, t_object *object);
int			intersect_sphere(t_intersect **head, t_ray ray, t_object *object);
int			intersect_cone(t_intersect **head, t_ray ray, t_object *object);
int			intersect_cylinder(t_intersect **head, t_ray ray, t_object *object);

#endif