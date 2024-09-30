/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/04 14:32:28 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:55:10 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	long unsigned int	index;
	char				*cptr;

	cptr = (char *)s;
	index = 0;
	while (index < n)
	{
		cptr[index] = (const int)c;
		index++;
	}
	return (cptr);
}
