/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   camera.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: marieke <marieke@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/11 13:31:42 by marieke       #+#    #+#                 */
/*   Updated: 2024/11/12 12:12:51 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <minirt.h>
# include <matrix.h>
# include <mini_mlx.h>

void		render(t_mlx *mlx_data, t_camera camera, t_world *world);
t_camera	new_camera(float height, float width, float fov, t_matrix transformation);
t_matrix	view_transformation(t_tuple from, t_tuple to, t_tuple up);

#endif