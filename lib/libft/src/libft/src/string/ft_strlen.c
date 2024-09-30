/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 13:57:49 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:56:11 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

size_t	ft_strlen(const char *s)
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
