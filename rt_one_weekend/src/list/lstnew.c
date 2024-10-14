/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstnew.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:51:45 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:39:41 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

t_hittable	*lstnew(t_hittable object)
{
	t_hittable	*new_node;

	new_node = calloc(sizeof(t_hittable), 1);
	if (new_node == NULL)
		return (NULL);
	new_node->type = object.type;
	new_node->next = NULL;
	return (new_node);
}
