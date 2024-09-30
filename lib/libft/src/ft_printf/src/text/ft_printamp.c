/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:44:00 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:34:48 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// This function uses ft_putchar_fd to print out ampersand

int	ft_printamp(void)
{
	int	rtr;

	rtr = 0;
	rtr += putchar_fd('%', 1);
	return (rtr);
}
