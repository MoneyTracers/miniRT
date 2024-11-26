/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:31:42 by marieke           #+#    #+#             */
/*   Updated: 2024/11/15 14:13:19 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include <minirt.h>
# include <matrix.h>
# include <mini_mlx.h>

void		render(t_mlx *mlx_data, t_camera camera, t_world *world);
void		new_camera(t_camera *cam, float fov, t_matrix transformation);
t_matrix	view_transformation(t_camera *cam, t_tuple from, t_tuple to, t_tuple up);

#endif