/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:49:59 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/22 16:16:06 by maraasve         ###   ########.fr       */
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
	cam->transformation = view_transformation(cam, from, to, create_vector(0, 1, 0));
	cam->inverse = invert_matrix(cam->transformation, 4);
	return (1);
}

#define rotation_angle 45

void	print_tuple(t_tuple tuple, char *str)
{
	printf("%s: x = %f | y = %f | z = %f\n", str, tuple.x, tuple.y, tuple.z);
}

#define MAX_PITCH 1.5  // About 85 degrees in radians

t_matrix rotation_around_axis(t_tuple axis, float angle) 
{
	t_matrix	rotation;
	float		cos_theta;
    float		sin_theta;
    float		one_minus_cos;

    axis = normalize(axis);
    
    cos_theta = cos(angle);
    sin_theta = sin(angle);
    one_minus_cos = 1.0f - cos_theta;
    
	rotation = create_identity_matrix();
	rotation.grid[0][0] = cos_theta + axis.x * axis.x * one_minus_cos;
	rotation.grid[0][1] = axis.x * axis.y * one_minus_cos - axis.z * sin_theta;
	rotation.grid[0][2] = axis.x * axis.z * one_minus_cos + axis.y * sin_theta;
	rotation.grid[1][0] = axis.y * axis.x * one_minus_cos + axis.z * sin_theta;
	rotation.grid[1][1] = cos_theta + axis.y * axis.y * one_minus_cos;
	rotation.grid[1][2] = axis.y * axis.z * one_minus_cos - axis.x * sin_theta;
	rotation.grid[2][0] = axis.z * axis.x * one_minus_cos - axis.y * sin_theta;
	rotation.grid[2][1] = axis.z * axis.y * one_minus_cos + axis.x * sin_theta;
	rotation.grid[2][2] = cos_theta + axis.z * axis.z * one_minus_cos;
    return (rotation);
}

int rotate_cam(int keycode, t_camera *cam) 
{
	t_matrix	rotation;
    t_tuple		look_point;
	t_tuple		target;
    float		angle;
	float		cur_pitch;
    
    target = add_tuple(cam->pos, cam->forward);
	if (keycode == A_KEY || keycode == D_KEY)
	{
		if (keycode == A_KEY)
			angle = -0.3;
		else
			angle = 0.3;

		rotation = rotation_around_axis(create_vector(0, 1, 0), angle);
	
		look_point = subtract_tuple(target, cam->pos);
		look_point = multiply_matrix_tuple(rotation, look_point);
		cam->forward = normalize(look_point);
	}
	else if (keycode == W_KEY || keycode == S_KEY) 
	{
		cur_pitch = asin(cam->forward.y);
	
		if (keycode == W_KEY)
			angle = 0.3;
		else
			angle = -0.3;
		if (cur_pitch + angle > MAX_PITCH || cur_pitch + angle < -MAX_PITCH)
			return (0);
		rotation = rotation_around_axis(cam->left, angle);
		look_point = subtract_tuple(target, cam->pos);
		look_point = multiply_matrix_tuple(rotation, look_point);
		cam->forward = normalize(look_point);
	}
	cam->transformation = view_transformation(cam, cam->pos, 
	add_tuple(cam->pos, cam->forward), create_vector(0, 1, 0));
	cam->inverse = invert_matrix(cam->transformation, 4);
	return (1);
}

int	keypress(int keycode, t_mlx *data)
{
	t_camera	*cam;
	int			changed;

	changed = 0;
	cam = &data->world->cam;
	if (keycode == ESC_KEY)
	{
		mlx_loop_end(data->mlx);
		return (1);
	}
	if (keycode == UP_KEY || keycode == DOWN_KEY || keycode == LEFT_KEY || keycode == RIGHT_KEY || keycode == ZOOM_IN || keycode == ZOOM_OUT)
		changed = move_cam(keycode, cam);
	else if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY || keycode == D_KEY)
		changed = rotate_cam(keycode, cam);
	if (changed)
	{
		render(data, *cam, data->world);
		if (data->img_count % 2)
			mlx_put_image_to_window(data->mlx, data->window, data->img1.image, 0, 0);
		else
			mlx_put_image_to_window(data->mlx, data->window, data->img2.image, 0, 0);
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
