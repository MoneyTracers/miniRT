/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   intersection.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:34:14 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/19 15:21:32 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_H
# define INTERSECTION_H

# include <tuples.h>
# include <calculations.h>

typedef struct s_object t_object; 
typedef struct s_color t_color; 
typedef struct s_world t_world; 

typedef struct	s_intersection
{
	float					t;
	t_object				*object;
	struct s_intersection	*next;
}	t_intersection;

typedef struct s_comps
{
	float	t;
	t_object	*object;
	t_tuple	point;
	t_tuple	over_point;
	t_tuple	eyev;
	t_tuple	normalv;
	t_tuple	reflectv;
	bool	inside;
}	t_comps;

typedef struct	s_ray
{
	t_fvec	origin;
	t_fvec	direction;
	float	t;
}	t_ray;

t_comps			prepare_comps(t_intersection *intersection, t_ray ray);
t_intersection	*intersect_world(t_world *world, t_ray ray);
t_color			color_at(t_world *world, t_ray ray, int *remaining);
t_intersection	*get_hit(t_intersection *intersections);
t_tuple			position(t_ray ray, float time);
t_tuple			normal_at(t_object *shape, t_tuple point);

#endif