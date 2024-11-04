/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reflection.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/31 15:26:36 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/04 15:24:05 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECTION_H
# define REFLECTION_H

# include <tuples.h>
# include <minirt.h>
# include <intersection.h>

t_color		reflected_color(t_world *world, t_comps comps, int *remaining);
t_tuple		reflect(t_tuple in, t_tuple normal);

#endif