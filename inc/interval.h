/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interval.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:18:14 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 17:57:52 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERVAL_H
# define INTERVAL_H

# include <minirt.h>

typedef struct s_interval
{
	float min;
	float max;
} t_interval;

float size(t_interval inv);
int contains(t_interval inv, float x);
int surround(t_interval inv, float x);
t_interval dinv(void);
t_interval inv(float min, float max);
float clamp(t_interval inv, float x);
t_interval inv_const(t_interval a, t_interval b);

#endif