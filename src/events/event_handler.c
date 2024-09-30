/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   event_handler.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 18:22:50 by spenning      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	keypress(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		free_all_mlx_success(data);
	}
	return (0);
}

int	destroy(t_data *data)
{
	free_all_mlx_success(data);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, keypress, data);
	mlx_hook(data->win, 17, 0L, destroy, data);
}
