/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:03:23 by spenning          #+#    #+#             */
/*   Updated: 2024/01/28 21:37:22 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// These are header guards that prevent the double definitions in the
// source file. This prevents library dependency from double copying
// libraries. if libft is already defined if won't define it again.
// name is LIBFT_H because the name should be the full filename of the
// header file, in all caps, with underscores for spaces and ​punctuation.

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//these inclusions are needed to be able to use the write function from
// unistd library. and va_list from the stdarg.h library. and the libft library

# include <stdarg.h>

// This function prints out the format string + variables 
// depending on which format specifiers are given. For example:
// ft_printf("Hello %s", s1);
// accepted formatters:
// %s	=	char*
// %d	=	int
// %i	=	int
// %p	=	void*
// %u	=	unsigned int
// %x	=	int
// %X	=	int 
int		ft_printf(const char *format, ...);

#endif
