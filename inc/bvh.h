/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:18:14 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/20 14:00:50 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

 typedef struct s_hitrecord
 {
	t_tuple p;
	t_tuple normal;
	float t;
	float u;
	float v;
 } t_hitrecord;

int random_int(int min, int max);
void sort_swap(t_object **a, t_object **b);
void sort(t_object ** world, int start, int end, int (*comp) (t_object* a, t_object* b));
int longest_axis(t_aabb bbox);
t_bvh	*bvh_node(t_object **world, size_t start, size_t end);
t_aabb sphere_bbox(t_tuple center, double radius);
float random_float_between(float min, float max);

#endif