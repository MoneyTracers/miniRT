/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bvh.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:18:14 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 17:46:50 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BVH_H
# define BVH_H

# include <minirt.h>

int random_int(int min, int max);
void sort_swap(t_object **a, t_object **b);
void sort(t_object ** world, int start, int end, int (*comp) (t_object* a, t_object* b));
int longest_axis(t_aabb bbox);

#endif