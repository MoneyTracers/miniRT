/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:22:50 by spenning          #+#    #+#             */
/*   Updated: 2024/11/19 13:01:16 by maraasve         ###   ########.fr       */
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
	t_matrix	translation;
	t_matrix	new_transformation;

	translation = create_identity_matrix();
	if (keycode == UP_KEY)
		translation = translation_matrix(0, -10, 0);
	else if (keycode == DOWN_KEY)
		translation = translation_matrix(0, 10, 0);
	else if (keycode == LEFT_KEY)
		translation = translation_matrix(-10, 0, 0);
	else if (keycode == RIGHT_KEY)
		translation = translation_matrix(10, 0, 0);
	else if (keycode == ZOOM_IN)
		translation = translation_matrix(cam->normal.x * 10, cam->normal.y * 10, cam->normal.z * 10);
	else if (keycode == ZOOM_OUT)
		translation = translation_matrix(-cam->normal.x * 10, -cam->normal.y * 10, -cam->normal.z * 10);
	
	new_transformation = multiply_matrices(translation, cam->tranformation);
	cam->tranformation = new_transformation;
	cam->inverse = invert_matrix(cam->tranformation, 4);
		return (0);
	return (1);
}

int	rotate_cam(int keycode, t_camera *cam)
{
	t_matrix	rotation;
	t_matrix	new_transformation;

	rotation = create_identity_matrix();
	if (keycode == W_KEY)
		rotation = rotate_x(degrees_to_radians(-45));
	else if (keycode == S_KEY)
		rotation = rotate_x(degrees_to_radians(45));
	else if (keycode == A_KEY)
		rotation = rotate_y(degrees_to_radians(45));
	else if (keycode == D_KEY)
		rotation = rotate_y(degrees_to_radians(-45));
	
	cam->normal = multiply_matrix_tuple(rotation, cam->normal);
	new_transformation = multiply_matrices(rotation, cam->tranformation);
	cam->tranformation = new_transformation;
	cam->inverse = invert_matrix(cam->tranformation, 4);
		return (0);
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

	if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == ZOOM_IN || keycode == ZOOM_OUT)
	{
		if (!move_cam(keycode, cam))
			return (0);
	}
	else if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY || keycode == D_KEY)
	{
		if (!rotate_cam(keycode, cam))
			return (0);
	}

	render(data, *cam, data->world);
	if (data->img_count % 2)
		mlx_put_image_to_window(data->mlx, data->window, data->img1.image, 0, 0);
	else
		mlx_put_image_to_window(data->mlx, data->window, data->img2.image, 0, 0);
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
