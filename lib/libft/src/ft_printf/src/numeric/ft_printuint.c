/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printuint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:45:03 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:34:25 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// This function converts the value passed from ft_printunit
// recursively and then writes out the value with ft_putchar_fd

static int	printunit(unsigned int arg)
{
	int	rtr;

	rtr = 0;
	if (arg == 0)
		rtr += putchar_fd('0', 1);
	if (arg > 0)
	{
		if (arg > 9)
			rtr += printunit(arg / 10);
		rtr += putchar_fd(48 + (arg % 10), 1);
	}
	return (rtr);
}
// This function retrieves the value from the va_list in 
// order to pass it to printunit

int	ft_printuint(va_list args)
{
	int				rtr;
	int				rtr_va_arg;
	unsigned int	arg;

	rtr = 0;
	rtr_va_arg = va_arg(args, int);
	arg = (unsigned int)rtr_va_arg;
	rtr = printunit(arg);
	return (rtr);
}
