/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   list.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:04:09 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/04 15:24:06 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

#include <shapes.h>
#include <lighting.h>

void	add_shape_to_list(t_object **head, t_object *new_shape);
void	add_light_to_list(t_light **head, t_light *new_light);

#endif