/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_strlen.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/30 15:30:49 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/30 15:32:36 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/ft_printf_internal.h"

size_t	strlen(const char *s)
{
	size_t	index;

	index = 0;
	if (s[index] == '\0')
	{
		return (0);
	}
	else
	{
		while (s[index] != '\0')
		{
			index++;
		}
		return (index);
	}
}
