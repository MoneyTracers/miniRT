/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:34:11 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/29 15:34:05 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <math.h>

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color;

t_color	new_color(float r, float g, float b);
t_color	add_colors(t_color one, t_color two);
t_color	colors_multi_scalar(t_color one, float scalar);
t_color	colors_multiply(t_color one, t_color two);
int		create_trgb(float t, float r, float g, float b);
t_color	clamp_color(t_color color);

#endif