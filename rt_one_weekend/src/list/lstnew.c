/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstnew.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:51:45 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/22 13:16:18 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

t_hittable	*lstnew(int type, t_vec3 center, double radius, t_material mat)
{
	t_hittable	*new_node;

	new_node = calloc(sizeof(t_hittable), 1);
	if (new_node == NULL)
		return (NULL);
	
	new_node->type = type;
	new_node->center = center;
	new_node->radius = radius;
	new_node->mat = mat;
	new_node->next = NULL;
	return (new_node);
}
