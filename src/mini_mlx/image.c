/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 17:25:06 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/04 15:24:13 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mini_mlx.h>

void	pixel_put(t_mlx *data, int x, int y, t_color color)
{
	char	*dst;
	int		color_int;

	color_int = create_trgb(255, color.r, color.g, color.b);
	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color_int;
	}
}
