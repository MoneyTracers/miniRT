/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:55:02 by maraasve          #+#    #+#             */
/*   Updated: 2024/12/03 13:59:41 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include <mini_mlx.h>
# include <intersection.h>
# include <shapes.h>
# include <transformation.h>

void	free_mlx(t_mlx *data);
void	free_intersection(t_intersect **intersection);
void	free_objects(t_object **head);
void	free_lights(t_light **head);
void	free_minirt(t_world *world);

#endif