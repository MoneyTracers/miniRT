/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:43:41 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:31:21 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <intersection.h>
#include <list.h>

int	intersect_sphere(t_intersect **head, t_ray ray, t_object *object)
{
	t_tuple			sphere_to_ray;
	float			discriminant;
	float			t;
	float			val[3];

	sphere_to_ray = subtract_tuple(ray.origin, object->sphere->center);
	val[A] = get_dot_product(ray.direction, ray.direction);
	val[B] = 2 * get_dot_product(ray.direction, sphere_to_ray);
	val[C] = get_dot_product(sphere_to_ray, sphere_to_ray) - 1;
	discriminant = get_discriminant(val[A], val[B], val[C]);
	if (discriminant < 0)
		return (SUCCESS);
	t = (-val[B] - sqrtf(discriminant)) / (2 * val[A]);
	if (add_intersect_sorted(head, new_intersect(t, object)) == ERROR)
		return (ERROR);
	t = (-val[B] + sqrtf(discriminant)) / (2 * val[A]);
	if (add_intersect_sorted(head, new_intersect(t, object)) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
