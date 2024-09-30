/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:37 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:33:53 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// This function takes the value from va_list and then
// uses ft_putnbr_fd to print out the value

int	ft_printint(va_list args)
{
	int	arg;
	int	rtr;

	arg = va_arg(args, int);
	rtr = 0;
	rtr = putnbr_fd(arg, 1);
	return (rtr);
}
