/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieke <marieke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:31:42 by marieke           #+#    #+#             */
/*   Updated: 2024/11/11 16:07:47 by marieke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <minirt.h>
# include <matrix.h>
# include <mini_mlx.h>

typedef struct s_camera
{
	int		image_width;
	int		image_heigth;
	float	fov;
	float	half_width;
	float	half_height;
	float	aspect_ratio;
	float	pixel_size;
	t_matrix	tranformation;
	t_matrix	*inverse;

	// int		samples_per_pixel;
	// int		max_depth;
	// double	pixel_samples_scale;
	// double	focal_length;
	// double	viewport_heigth;
	// double	viewport_width;
	// t_tuple	lookfrom;
	// t_tuple	lookat;
	// t_tuple	vup;
	// t_tuple	viewport_u;
	// t_tuple	viewport_v;
	// t_tuple	center;
	// t_tuple	pixel_delta_u;
	// t_tuple	pixel_delta_v;
	// t_tuple	viewport_upper_left;
	// t_tuple	pixel00_loc;
}	t_camera;

void		render(t_mlx *mlx_data, t_camera camera, t_world *world);
t_camera	new_camera(float height, float width, float fov, t_matrix transformation);
t_matrix	view_transformation(t_tuple from, t_tuple to, t_tuple up);

#endif