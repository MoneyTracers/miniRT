/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/22 15:49:59 by maraasve      #+#    #+#                 */
/*   Updated: 2024/12/12 14:55:16 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <mini_mlx.h>
#include <mlx.h>
#include <camera.h>
#include <free.h>
#include <matrix.h>
#include <transformation.h>

int	keypress(int keycode, t_mlx *data)
{
	t_camera	*cam;

	cam = &data->world->cam;
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	return (1);
}

int	destroy(t_mlx *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	hooks(t_mlx *data)
{
	mlx_hook(data->window, 2, 1L << 0, keypress, data);
	mlx_hook(data->window, 17, 0L, destroy, data);
}
