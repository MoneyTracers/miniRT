/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:44:06 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 14:39:34 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

float	get_dot_product(t_tuple vector1, t_tuple vector2)
{
	float	dot_product;

	dot_product = vector1.x * vector2.x \
				+ vector1.y * vector2.y \
				+ vector1.z * vector2.z \
				+ vector1.w * vector2.w;
	return (dot_product);
}

t_tuple	get_cross_product(t_tuple vector1, t_tuple vector2)
{
	t_tuple	cross_product;

	cross_product.x = vector1.y * vector2.z \
							- vector1.z * vector2.y;
	cross_product.y = vector1.z * vector2.x \
							- vector1.x * vector2.z;
	cross_product.z = vector1.x * vector2.y \
							- vector1.y * vector2.x;
	cross_product.w = 0.0;
	return (cross_product);
}

float	get_magnitude(t_tuple vector)
{
	float	magnitude;

	magnitude = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) \
				+ powf(vector.z, 2));
	return (magnitude);
}
