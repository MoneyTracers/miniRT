/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:16:15 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/06 14:03:22 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

bool	is_vector(t_tuple tuple)
{
	if (tuple.w == 0.0)
		return (true);
	return (false);
}

t_tuple	create_vector(float x, float y, float z)
{
	t_tuple	new;

	new.x = x;
	new.y = y;
	new.z = z;
	new.w = 0.0;
	return (new);
}

t_tuple	scale_vector(t_tuple vector, float scale)
{
	t_tuple new;

	new.x = vector.x * scale;
	new.y = vector.y * scale;
	new.z = vector.z * scale;
	new.w = vector.w * scale;
	return (new);
}

t_tuple	negate_vector(t_tuple vector)
{
	t_tuple	negated;

	negated.x = -vector.x;
	negated.y = -vector.y;
	negated.z = -vector.z;
	negated.w = vector.w;
	return (negated);
}

float	get_magnitude(t_tuple vector)
{
	float	magnitude;

	magnitude = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) \
				+ powf(vector.z, 2) + powf(vector.w, 2));
	return (magnitude);
}

t_tuple	normalize(t_tuple vector)
{
	t_tuple	normalized;
	float	magnitude;

	magnitude = get_magnitude(vector);
	normalized.x = vector.x / magnitude;
	normalized.y = vector.y / magnitude;
	normalized.z = vector.z / magnitude;
	normalized.w = vector.w / magnitude;
	return (normalized);
}

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

	cross_product.x = vector1.y* vector2.z \
							- vector1.z * vector2.y;
	cross_product.y = vector1.z * vector2.x \
							- vector1.x * vector2.z;
	cross_product.z = vector1.x * vector2.y \
							- vector1.y * vector2.x;
	cross_product.w = 0.0;
	return (cross_product);
}
