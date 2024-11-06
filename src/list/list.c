/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:43 by marieke           #+#    #+#             */
/*   Updated: 2024/11/06 15:36:59 by maraasve         ###   ########.fr       */
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

t_light	*new_light(t_tuple pos, t_color color, float intensity)
{
	t_light	*new;

	new = malloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->pos = pos;
	new->intensity = intensity;
	new->color = color;
	new->next = NULL;
	return (new);
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
