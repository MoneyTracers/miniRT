/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:54:57 by marieke           #+#    #+#             */
/*   Updated: 2024/11/11 16:13:11 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <camera.h>
#include <transformation.h>
#include <calculations.h>
#include <free.h>

t_matrix	view_matrix(t_tuple left, t_tuple forward, t_tuple up)
{
	t_matrix	transform;

	transform = create_identity_matrix();
	//error handling
	transform.grid[0][0] = left.x;
	transform.grid[0][1] = left.y;
	transform.grid[0][2] = left.z;
	transform.grid[1][0] = up.x;
	transform.grid[1][1] = up.y;
	transform.grid[1][2] = up.z;
	transform.grid[2][0] = -forward.x;
	transform.grid[2][1] = -forward.y;
	transform.grid[2][2] = -forward.z;
	return (transform);
}

t_matrix	view_transformation(t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	orientation;
	t_matrix	translation;
	t_matrix	transformation;
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;

	forward = normalize(subtract_tuple(to, from));
	left = get_cross_product(forward, normalize(up));
	true_up = get_cross_product(left, forward);
	orientation = view_matrix(left, forward, true_up);
	//error handling
	translation = translation_matrix(-from.x, -from.y, -from.z);
	//error handling
	transformation = multiply_matrices(orientation, translation);
	free_matrix(orientation.grid, 4);
	free_matrix(translation.grid, 4);
	return (transformation);
}

t_camera	new_camera(float height, float width, float fov, t_matrix transformation)
{
	t_camera	camera;
	float		half_view;

	camera.image_heigth = height;
	camera.image_width = width;
	camera.fov = fov;
	half_view = tanf(fov / 2);
	camera.aspect_ratio = height / width;
	if (camera.aspect_ratio >= 1)
	{
		camera.half_width = half_view;
		camera.half_height = half_view / camera.aspect_ratio;
	}
	else
	{
		camera.half_height = half_view;
		camera.half_width = half_view * camera.aspect_ratio;
	}
	camera.pixel_size = (camera.half_width * 2) / height;
	camera.tranformation = transformation;
	camera.inverse = invert_matrix(transformation.grid, 4);
	//error handling
	return (camera);
}

t_ray	ray_for_pixel(t_camera camera, int x, int y)
{
	t_ray	ray;
	t_tuple	pixel;
	float	xoffset;
	float	yoffset;
	float	world_x;
	float	world_y;

	xoffset = ((float)x + 0.5) * camera.pixel_size;
	yoffset = ((float)y + 0.5) * camera.pixel_size;
	world_x = camera.half_width - xoffset;
	world_y = camera.half_height - yoffset;
	pixel = multiply_matrix_tuple(*camera.inverse, create_point(world_x, world_y, -1));
	ray.origin = multiply_matrix_tuple(*camera.inverse, create_point(0, 0, 0));
	ray.direction = normalize(subtract_tuple(pixel, ray.origin));
	return (ray); 
}

void	render(t_mlx *mlx_data, t_camera camera, t_world *world)
{
	t_ray	ray;
	t_color	color;
	int		x;
	int		y;
	int		i;

	x = 0;
	while(x < camera.image_width)
	{
		y = 0;
		while (y < camera.image_heigth)
		{
			i = 5;
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray, &i);
			pixel_put(mlx_data, x, y, color);
			y++;
		}
		x++;
	}
}