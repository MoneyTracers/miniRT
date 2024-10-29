/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 14:47:44 by maraasve      #+#    #+#                 */
/*   Updated: 2024/10/29 15:02:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <tuples.h>

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
	t_color new;

	new.r = one.r + two.r;
	new.g = one.g + two.g;
	new.b = one.b + two.b;
	return (new);
}

t_color	subtract_colors(t_color one, t_color two)
{
	t_color new;

	new.r = one.r - two.r;
	new.g = one.g - two.g;
	new.b= one.b- two.b;
	return (new);
}

t_color	colors_multi_scalar(t_color one, float scalar)
{
	t_color new;

	new.r = one.r * scalar;
	new.g = one.g * scalar;
	new.b = one.b * scalar;
	return (new);
}

t_color	colors_multiply(t_color one, t_color two)
{
	t_color new;

	new.r = one.r * two.r;
	new.g = one.g * two.g;
	new.b = one.b * two.b;
	return (new);
}

int	create_trgb(float t, float r, float g, float b)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	// Clamp the float values between 0 and 1, then scale to 0-255
	red = (int)(r * 255.0);
	green = (int)(g * 255.0);
	blue = (int)(b * 255.0);
	alpha = (int)(t * 255.0); // Transparency (optional, can set to 255 for full opacity)

	// Combine into a single int in the format 0xTTRRGGBB
	return (alpha << 24 | red << 16 | green << 8 | blue);
}

t_color clamp_color(t_color color) 
{
    color.r = fminf(fmaxf(color.r, 0.0), 1.0);
    color.g = fminf(fmaxf(color.g, 0.0), 1.0);
    color.b = fminf(fmaxf(color.b, 0.0), 1.0);
    return color;
}
