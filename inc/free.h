/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 14:55:02 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/15 17:16:10 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

#include <minirt.h>
# include <mini_mlx.h>
# include <intersection.h>
# include <shapes.h>
# include <transformation.h>

void	free_mlx(t_mlx *data);
void	free_matrix(float **grid, int size);
void	free_intersection(t_intersection **intersection);
void	free_objects(t_object **head);
void	free_lights(t_light **head);
void	free_transformation_matrix(t_transformation *transform);

#endif