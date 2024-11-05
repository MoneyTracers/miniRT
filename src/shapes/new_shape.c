/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:30:07 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/05 14:24:44 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <tuples.h>

t_cylinder new_cylinder(float min, float max, bool capped)
{
	t_cylinder	new;

	new.min = min;
	new.max = max;
	new.capped = capped;
	return (new);
}

t_sphere	new_sphere(void)
{
	t_sphere	new;

	new.center = create_point(0, 0, 0);
	new.radius = 1;
	return (new);
}

t_plane	new_plane(t_tuple normal)
{

}