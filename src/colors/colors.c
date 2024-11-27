/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:47:44 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/27 12:52:01 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <color.h>

t_color	new_color(float r, float g, float b)
{
	t_color	new;

	new.r = r;
	new.g = g;
	new.b = b;
	return (new);
}

t_color	add_colors(t_color one, t_color two)
{
	t_color	new;

	new.r = one.r + two.r;
	new.g = one.g + two.g;
	new.b = one.b + two.b;
	return (new);
}

// t_color	subtract_colors(t_color one, t_color two)
// {
// 	t_color	new;

// 	new.r = one.r - two.r;
// 	new.g = one.g - two.g;
// 	new.b = one.b- two.b;
// 	return (new);
// }
// DELETE THIS

t_color	colors_multi_scalar(t_color one, float scalar)
{
	t_color	new;

	new.r = one.r * scalar;
	new.g = one.g * scalar;
	new.b = one.b * scalar;
	return (new);
}

t_color	colors_multiply(t_color one, t_color two)
{
	t_color	new;

	new.r = one.r * two.r;
	new.g = one.g * two.g;
	new.b = one.b * two.b;
	return (new);
}

t_color	clamp_color(t_color color)
{
	color.r = fminf(fmaxf(color.r, 0.0), 255.0);
	color.g = fminf(fmaxf(color.g, 0.0), 255.0);
	color.b = fminf(fmaxf(color.b, 0.0), 255.0);
	return (color);
}
