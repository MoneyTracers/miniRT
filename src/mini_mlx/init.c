/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:42:41 by marieke           #+#    #+#             */
/*   Updated: 2024/11/15 14:33:09 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_mlx.h>
#include <mlx.h>
#include <free.h>

int	init_img(t_mlx *data, t_img *img)
{
	img->image = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->img1.image)
	{
		free_mlx(data);
		return (0);
	}
	img->addr = mlx_get_data_addr(img->image, &img->bpp,
			&img->line_length, &img->endian);
	if (!img->addr)
	{
		free_mlx(data);
		return (0);
	}
	return (1);
}

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
	if (!init_img(data, &data->img1))
		return (0);
	if (!init_img(data, &data->img2))
		return (0);
	return (1);
}