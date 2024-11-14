/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:18:14 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 18:04:57 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB_H
# define AABB_H

# include <minirt.h>
# include <interval.h>
# include <intersection.h>

typedef struct s_aabb
{
	t_interval x;
	t_interval y;
	t_interval z;
} t_aabb;

t_aabb aabb(t_interval x, t_interval y, t_interval z);
t_aabb aabb_vec(t_tuple a, t_tuple b);
t_aabb aabb_const(t_aabb a, t_aabb b);
int aabb_hit(t_aabb aabb, t_ray r, t_interval ray_t);
t_interval axis_interval(t_aabb aabb, int n);
t_aabb sphere_bbox(t_tuple center, double radius);

#endif
