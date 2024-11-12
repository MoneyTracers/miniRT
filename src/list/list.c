/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/19 12:09:43 by marieke       #+#    #+#                 */
/*   Updated: 2024/11/12 13:50:56 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <list.h>

void	add_shape_to_list(t_object **head, t_object *new_shape)
{
	t_object	*cur;

	if (!head || !new_shape)
		return ;
	if (!*head)
	{
		*head = new_shape;
		new_shape->next = NULL;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_shape;
	new_shape->next = NULL;
}

void	add_light_to_list(t_light **head, t_light *new_light)
{
	t_light	*cur;

	if (!head || !new_light)
		return ;
	if (!*head)
	{
		*head = new_light;
		new_light->next = NULL;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new_light;
	new_light->next = NULL;
}
