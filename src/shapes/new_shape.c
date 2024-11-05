/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_shape->c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:30:07 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/05 15:53:15 by maraasve         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include <shapes.h>
#include <tuples.h>

t_object	*new_cylinder(float min, float max, bool capped)
{
	t_cylinder	*cyl;

	cyl = malloc(sizeof(t_cylinder));
	if (!cyl)
		return (NULL);
	cyl->min = min;
	cyl->max = max;
	cyl->capped = capped;
	return (cyl);
}

t_sphere	*new_sphere(void)
{
	t_sphere	*sphere;

	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = create_point(0, 0, 0);
	sphere->radius = 1;
	return (sphere);
}

t_plane	*new_plane(t_tuple normal)
{
	t_plane	*plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->normal = normal;
	return (plane);
}

t_cone	*new_cone(float min, float max, bool capped)
{
	t_cone	*cone;

	cone = malloc(sizeof(t_cone));
	if (!cone)
		return (NULL);
	cone->min = min;
	cone->max = max;
	cone->capped = capped;
	return (cone);
}
