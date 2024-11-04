/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/02 12:42:41 by marieke       #+#    #+#                 */
/*   Updated: 2024/11/04 15:24:14 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mini_mlx.h>
#include <mlx.h>
#include <free.h>

int	init_mlx(t_mlx *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	if (!data->window)
	{
		free(data->mlx);
		return (0);
	}
	data->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->image)
	{
		free_mlx(data);
		return (0);
	}
	data->addr = mlx_get_data_addr(data->image, &data->bpp,
			&data->line_length, &data->endian);
	if (!data->addr)
	{
		free_mlx(data);
		return (0);
	}
	return (1);
}