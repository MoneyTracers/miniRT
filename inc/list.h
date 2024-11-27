/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:04:09 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/27 14:54:17 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <shapes.h>
#include <lighting.h>
#include <intersection.h>

void			add_shape_to_list(t_object **head, t_object *new_shape);
void			add_light_to_list(t_light **head, t_light *new_light);
int				add_intersect_sorted(t_intersection **head, t_intersection *new);
t_intersection	*new_intersect(float t, t_object *object);

#endif