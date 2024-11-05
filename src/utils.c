/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 13:16:49 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/05 13:58:32 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <calculations.h>
#include <libft.h>

void	debugger(char *format, ...)
{
	va_list	ptr;

	if (DEBUG == 1)
	{
		va_start(ptr, format);
		ft_printf(format, ptr);
		va_end(ptr);
	}
}


float	ft_abs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

bool	equal_float(float a, float b)
{
	if (ft_abs(a - b) > EPSILON)
		return (false);
	return (true);
}
