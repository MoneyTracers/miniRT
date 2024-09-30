/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 18:35:03 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:54:52 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// this function compares 

#include "../../../../inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*s1_cptr;
	unsigned char	*s2_cptr;

	index = 0;
	s1_cptr = (unsigned char *)s1;
	s2_cptr = (unsigned char *)s2;
	if (n == 0)
	{
		return (0);
	}
	while (index < n)
	{
		if (*(s1_cptr + index) != *(s2_cptr + index))
		{
			return (*(s1_cptr + index) - *(s2_cptr + index));
		}
		index++;
	}
	return (0);
}
