/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:54:57 by marieke           #+#    #+#             */
/*   Updated: 2024/11/27 14:21:02 by maraasve         ###   ########.fr       */
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

t_matrix	view_transform(t_camera *cam, t_tuple from, t_tuple to, t_tuple up)
{
	t_matrix	orientation;
	t_matrix	translation;
	t_matrix	transformation;

	cam->pos = from; //CAM->POS 0,0,0 NOT WORKING
	cam->normal = to;
	cam->forward = normalize(subtract_tuple(to, from));
	if (ft_fabs(cam->normal.y) > 0.9)
		up = create_vector(0, 0, 1);
	cam->left = normalize(get_cross_product(cam->forward, normalize(up)));
	cam->true_up = normalize(get_cross_product(cam->left, cam->forward));
	orientation = view_matrix(cam->left, cam->forward, cam->true_up);
	translation = translation_matrix(-from.x, -from.y, -from.z);
	transformation = multiply_matrices(orientation, translation);
	return (transformation);
}

void	new_camera(t_camera *cam, float fov, t_matrix transformation)
{
	float		half_view;

	cam->image_heigth = HEIGHT;
	cam->image_width = WIDTH;
	cam->fov = fov;
	half_view = tanf(fov / 2);
	cam->aspect_ratio = HEIGHT / WIDTH;
	if (cam->aspect_ratio >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / cam->aspect_ratio;
	}
	else
	{
		cam->half_height = half_view;
		cam->half_width = half_view * cam->aspect_ratio;
	}
	cam->pixel_size = (cam->half_width * 2) / HEIGHT;
	cam->transformation = transformation;
	cam->inverse = invert_matrix(transformation, 4);
}

t_ray	ray_for_pixel(t_camera camera, int x, int y)
{
	t_ray	ray;
	t_tuple	pixel;
	float	offset[2];
	float	world[2];

	offset[X] = ((float)x + 0.5) * camera.pixel_size;
	offset[Y] = ((float)y + 0.5) * camera.pixel_size;
	world[X] = camera.half_width - offset[X];
	world[Y] = camera.half_height - offset[Y];
	pixel = multiply_matrix_tuple(camera.inverse, \
			create_point(world[X], world[Y], -1));
	ray.origin = multiply_matrix_tuple(camera.inverse, create_point(0, 0, 0));
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

	mlx_data->img_count++;
	x = 0;
	while (x < camera.image_width)
	{
		y = 0;
		while (y < camera.image_heigth)
		{
			i = 5;
			ray = ray_for_pixel(camera, x, y);
			color = color_at(world, ray, &i);
			if (mlx_data->img_count % 2)
				pixel_put(&mlx_data->img1, x, y, color);
			else
				pixel_put(&mlx_data->img2, x, y, color);
			y++;
		}
		x++;
	}
}
