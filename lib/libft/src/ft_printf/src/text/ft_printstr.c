/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:57 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:37:38 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// this function retrieves the value from the va_list
// and then goes through the string and prints the string 
// with ft_putchar_fd while returning the len printed with 
// rtr

int	ft_printstr(va_list args)
{
	int		rtr;
	char	*str;

	str = va_arg(args, char *);
	rtr = 0;
	if (str == NULL)
		rtr = putstr_fd("(null)", 1);
	else
	{
		while (*str)
		{
			rtr += putchar_fd(str[0], 1);
			str++;
		}
	}
	return (rtr);
}
