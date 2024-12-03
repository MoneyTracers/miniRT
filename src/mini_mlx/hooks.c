/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:59 by maraasve          #+#    #+#             */
/*   Updated: 2024/12/03 17:34:59 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mini_mlx.h>
#include <mlx.h>
#include <camera.h>
#include <free.h>
#include <matrix.h>
#include <transformation.h>

int	move_cam(int keycode, t_camera *cam)
{
	t_tuple		from;
	t_tuple		to;

	from = cam->pos;
	if (keycode == UP_KEY)
		from = add_tuple(from, scale_tuple(cam->true_up, 10));
	else if (keycode == DOWN_KEY)
		from = subtract_tuple(from, scale_tuple(cam->true_up, 10));
	else if (keycode == LEFT_KEY)
		from = add_tuple(from, scale_tuple(cam->left, 10));
	else if (keycode == RIGHT_KEY)
		from = subtract_tuple(from, scale_tuple(cam->left, 10));
	else if (keycode == ZOOM_IN)
		from = add_tuple(from, scale_tuple(cam->forward, 10));
	else if (keycode == ZOOM_OUT)
		from = subtract_tuple(from, scale_tuple(cam->forward, 10));
	to = add_tuple(from, cam->forward);
	cam->transformation = view_transform(cam, from, to, create_vector(0, 1, 0));
	cam->inverse = invert_matrix(cam->transformation, 4);
	return (1);
}

int	keypress(int keycode, t_mlx *data)
{
	t_camera	*cam;

	cam = &data->world->cam;
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY || \
		keycode == RIGHT_KEY || keycode == ZOOM_IN || keycode == ZOOM_OUT)
	{
		move_cam(keycode, cam);
		render(data, *cam, data->world);
		if (data->img_count % 2)
			mlx_put_image_to_window(data->mlx, data->window, \
									data->img1.image, 0, 0);
		else
			mlx_put_image_to_window(data->mlx, data->window, \
									data->img2.image, 0, 0);
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
