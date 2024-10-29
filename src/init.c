/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:42:41 by marieke           #+#    #+#             */
/*   Updated: 2024/10/14 15:16:46 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

int	init_mlx(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->window = mlx_new_window(data->mlx, WIDTH, HEIGHT, "sphere");
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
	if (data->addr == NULL)
	{
		free_mlx(data);
		return (0);
	}
	return (1);
}