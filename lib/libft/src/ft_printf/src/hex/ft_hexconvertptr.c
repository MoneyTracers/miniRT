/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexconvertptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:43:41 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:37:55 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// This function converts the value passed from ft_printptr to 
// hexidecimal recursively

int	ft_hexconvertptr(long unsigned int arg)
{
	int	rtr;
	int	rem_int;

	rtr = 0;
	rem_int = 0;
	if (arg > 0)
	{
		rtr += ft_hexconvertptr(arg / 16);
		rem_int = arg % 16;
		if (rem_int > 9)
			rem_int += 55;
		else
			rem_int += 48;
		rtr += putchar_fd(tolower(rem_int), 1);
	}
	return (rtr);
}
