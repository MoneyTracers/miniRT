/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:43 by marieke           #+#    #+#             */
/*   Updated: 2024/10/29 16:04:16 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_object_base	*new_object_base(int type, t_matrix transformation)
{
	t_object_base	*new;

	new = malloc(sizeof(t_object));
	if(!new)
		return (NULL);
	new->type = type;
	new->transformation = transformation;
	if (!is_identity_matrix(transformation.grid, 4))
		new->inverted = invert_matrix(transformation.grid, 4);
	else
		new->inverted = NULL;
	return (new);
}

void	add_shape_to_list(t_object **head, t_object *new)
{
	t_object	*cur;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		new->next = NULL;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->next = NULL;	
}

void	add_light_to_list(t_light **head, t_light *new)
{
	t_light	*cur;

	if (!head || !new)
		return ;
	if (!*head)
	{
		*head = new;
		new->next = NULL;
		return ;
	}
	cur = *head;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->next = NULL;
}
