/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:06:16 by marieke           #+#    #+#             */
/*   Updated: 2024/11/05 13:27:16 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>

t_object_base	*new_object_base(t_matrix transformation, t_material material)
{
	t_object_base	*new;

	new = malloc(sizeof(t_object));
	if(!new)
		return (NULL);
	new->transformation = transformation;
	if (!is_identity_matrix(transformation.grid, 4))
		new->inverted = invert_matrix(transformation.grid, 4);
	else
		new->inverted = NULL;
	return (new);
}

t_object	*new_object(int type, t_object_base *base)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->base = base;
	new->next = NULL;
	return (new);
}
