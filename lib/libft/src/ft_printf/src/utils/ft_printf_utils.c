/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_utils.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/12 18:10:24 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/30 15:30:34 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf_internal.h"

int	putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

int	putstr_fd(char *s, int fd)
{
	size_t	len;

	len = strlen(s);
	write(fd, s, len);
	return (len);
}

int	putnbr_fd(int d, int fd)
{
	int			rtr;
	long int	ld;

	ld = (long int)d;
	rtr = 0;
	if (ld < 0)
	{
		rtr += putchar_fd('-', fd);
		ld *= -1;
	}
	if (ld == 0)
		rtr += putchar_fd('0', fd);
	if (ld > 0)
	{
		if (ld > 9)
		{
			rtr += putnbr_fd(ld / 10, fd);
		}
		rtr += putchar_fd(48 + (ld % 10), fd);
	}
	return (rtr);
}

int	tolower(int c)
{
	if (c > 64 && c < 91)
	{
		c = c + 32;
		return (c);
	}
	else
	{
		return (c);
	}
}

int	toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
