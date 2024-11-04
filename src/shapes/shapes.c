/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shapes.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/19 13:06:16 by marieke       #+#    #+#                 */
/*   Updated: 2024/11/04 15:24:15 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>

t_object	*new_object(t_tuple center, float radius, t_material material, t_object_base *base)
{
	t_object	*new;

	new = malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->center = center;
	new->radius = radius;
	new->material = material;
	new->base = base;
	new->next = NULL;
	return (new);
}
