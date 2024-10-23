/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstnew.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:51:45 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/23 16:11:07 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>


t_aabb sphere_bbox(t_vec3 center, double radius)
{
	t_vec3 rvec;

	rvec = vec(radius, radius, radius);
	return (aabb_vec(vec_sub(center, rvec), vec_add(center, rvec)));
}


t_hittable	*lstnew(int type, t_vec3 center, double radius, t_material mat)
{
	t_hittable	*new_node;

	new_node = calloc(sizeof(t_hittable), 1);
	if (new_node == NULL)
		return (NULL);
	if (type == sphere)
		new_node->bbox = sphere_bbox(center, radius);
	new_node->type = type;
	new_node->center = center;
	new_node->radius = radius;
	new_node->mat = mat;
	new_node->next = NULL;
	return (new_node);
}
