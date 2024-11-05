/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 13:06:16 by marieke           #+#    #+#             */
/*   Updated: 2024/11/05 17:24:51 by maraasve         ###   ########.fr       */
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

t_material	default_material(void)
{
	t_material	material;

	material.color.r = 1;
	material.color.g = 1;
	material.color.b = 1;
	material.ambient = 0.3;
	material.diffuse = 0.9;
	material.specular = 0.9;
	material.shininess = 200.0;
	material.reflective = 0;
	return (material);
}
