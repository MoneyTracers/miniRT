/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 12:09:43 by marieke           #+#    #+#             */
/*   Updated: 2024/11/29 15:31:42 by maraasve         ###   ########.fr       */
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

t_intersect	*new_intersect(float t, t_object *object)
{
	t_intersect	*new;

	new = malloc(sizeof(t_intersect));
	if (!new)
		return (NULL);
	new->t = t;
	new->object = object;
	new->next = NULL;
	return (new);
}

int	add_intersect_sorted(t_intersect **head, t_intersect *new)
{
	t_intersect	*cur;
	t_intersect	*prev;

	if (!head || !new)
		return (ERROR);
	if (!*head || (*head)->t >= new->t)
	{
		new->next = *head;
		*head = new;
		return (SUCCESS);
	}
	prev = NULL;
	cur = (*head);
	while (cur && cur->t <= new->t)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = new;
	new->next = cur;
	return (SUCCESS);
}
