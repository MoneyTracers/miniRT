/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:48 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:34:01 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// this function retrieves the value from va_list
// then it will put the two's complement before
// passing the value to ft_hexconverptr

int	ft_printptr(va_list args)
{
	int				rtr;
	long unsigned	arg;

	arg = va_arg(args, long unsigned int);
	if (arg == 0)
	{
		rtr = putstr_fd("(nil)", 1);
		return (rtr);
	}
	rtr = 0;
	rtr += putchar_fd('0', 1);
	rtr += putchar_fd('x', 1);
	rtr += ft_hexconvertptr(arg);
	return (rtr);
}
