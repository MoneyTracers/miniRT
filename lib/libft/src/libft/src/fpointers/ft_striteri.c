/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_striteri.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/15 21:56:09 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:55:51 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// this function will accept a string and a function pointer.
// Then to each character of the string the function will be applied
// until we reach the null terminator of the string

#include "../../../../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;
	size_t			s_len;

	index = 0;
	s_len = ft_strlen((const char *)s);
	while (index < s_len)
	{
		f(index, s);
		s++;
		index++;
	}
	return ;
}
