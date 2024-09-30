/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_init.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/12 15:49:54 by spenning      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		exit(EXIT_FAILURE);
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "fdf");
	if (data->win == NULL)
		free_dis(data);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (data->img == NULL)
		free_win(data);
	data->addr = mlx_get_data_addr(data->img, &data->bpp,
			&data->line_length, &data->endian);
	if (data->addr == NULL)
		free_img(data);
	map_init(data);
	data->width = WIDTH;
	data->height = HEIGHT;
}
