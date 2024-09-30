/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pixel.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 18:24:16 by spenning      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < WIDTH && x > 0 && y < HEIGHT && y > 0)
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
