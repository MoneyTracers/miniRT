/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   interval.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/14 17:48:42 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/11/14 17:57:46 by mynodeus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <interval.h>

float size(t_interval inv)
{
	return (inv.max - inv.min);
}

int contains(t_interval inv, float x)
{
	if ((inv.min <= x) && (x <= inv.max))
		return (1);
	return (0);
}

int surround(t_interval inv, float x)
{
	if ((inv.min < x) && (x < inv.max))
		return (1);
	return (0);
}

float clamp(t_interval inv, float x)
{
	if (inv.min > x)
		return (inv.min);
	if (inv.max < x)
		return (inv.max);
	return (x);
}


t_interval dinv(void)
{
	t_interval new;

	new.min = 0;
	new.max = 0;
	return (new);
}
t_interval inv(float min, float max)
{
	t_interval new;

	new.min = min;
	new.max = max;
	return (new);
}

t_interval inv_const(t_interval a, t_interval b)
{
	t_interval new;

	if (a.min <= b.min)
		new.min = a.min;
	else 
		new.min = b.min;
	if (a.max >= b.max)
		new.max = a.max;
	else
		new.max = b.max;
	return (new);
}
