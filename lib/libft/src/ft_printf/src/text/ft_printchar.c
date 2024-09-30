/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printchar.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/03 10:44:06 by spenning      #+#    #+#                 */
/*   Updated: 2023/12/21 15:07:34 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// This function takes the value from va_list and then uses
// write to output the char 

int	ft_printchar(va_list args)
{
	int	c;

	c = va_arg(args, int);
	c = (char)c;
	write(1, &c, 1);
	return (1);
}
