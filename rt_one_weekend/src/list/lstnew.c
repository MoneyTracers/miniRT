/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstnew.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:51:45 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/26 17:34:35 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

t_hittable	*lstnew(int type, t_ray center, double radius, t_material mat)
{
	t_hittable	*new_node;

	new_node = calloc(sizeof(t_hittable), 1);
	if (new_node == NULL)
		return (NULL);
	if (type == sphere)
		new_node->bbox = sphere_bbox(center.org, radius);
	new_node->type = type;
	new_node->center = center;
	new_node->radius = radius;
	new_node->mat = mat;
	new_node->next = NULL;
	return (new_node);
}
