/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:45:10 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:34:33 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf.h"
#include "../../inc/ft_printf_internal.h"

// This function will check the datatype that is passed from printf
// if this datatype matches one of datatypes that this printf can print it will
// call its matching function

static int	check_datatype(const char specifier, va_list args)
{
	int	rtr;

	rtr = 0;
	if (specifier == 'c')
		rtr = ft_printchar(args);
	if (specifier == 's')
		rtr = ft_printstr(args);
	if (specifier == 'd')
		rtr = ft_printint(args);
	if (specifier == 'i')
		rtr = ft_printint(args);
	if (specifier == 'u')
		rtr = ft_printuint(args);
	if (specifier == '%')
		rtr = ft_printamp();
	if (specifier == 'x' || specifier == 'X')
		rtr = ft_printhex(args, specifier);
	if (specifier == 'p')
		rtr = ft_printptr(args);
	return (rtr);
}

// This is the main function where printf starts
// this function will go through the entire string one byte at a time
// if a formatter is found then it will check the datatype
// otherwise it will print the string

int	ft_printf(const char *format, ...)
{
	int		rtr;
	va_list	args;

	rtr = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			rtr += check_datatype(format[1], args);
			format += 2;
		}
		else
		{
			rtr += putchar_fd(format[0], 1);
			format++;
		}
	}
	va_end(args);
	return (rtr);
}
