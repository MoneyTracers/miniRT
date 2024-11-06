/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: maraasve <maraasve@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/01 13:16:49 by maraasve      #+#    #+#                 */
/*   Updated: 2024/11/06 15:40:25 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <calculations.h>
#include <libft.h>
#include <stdarg.h>

void	debugger(char *format, ...)
{
	va_list	ptr;

	if (DEBUG == 1)
	{
		va_start(ptr, format);
		vdprintf(2, format, ptr);
		va_end(ptr);
	}
}


float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

bool	equal_float(float a, float b)
{
	if (ft_fabs(a - b) > EPSILON)
		return (false);
	return (true);
}
