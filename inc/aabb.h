/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aabb.h                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:18:14 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 17:21:15 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AABB_H
# define AABB_H

# include <minirt.h>
# include <interval.h>

typedef struct s_aabb
{
	t_interval x;
	t_interval y;
	t_interval z;
}	t_aabb;

#endif
