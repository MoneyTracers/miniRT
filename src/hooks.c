/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:22:50 by spenning          #+#    #+#             */
/*   Updated: 2024/10/14 15:53:04 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

int	keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_loop_end(data->mlx);
	}
	return (0);
}

int	destroy(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->window, 2, 1L << 0, keypress, data);
	mlx_hook(data->window, 17, 0L, destroy, data);
}
