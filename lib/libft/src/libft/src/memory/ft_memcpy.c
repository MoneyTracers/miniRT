/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 21:30:56 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:54:58 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	long unsigned int	index;
	const char			*src_cptr;
	char				*dest_cptr;

	index = 0;
	src_cptr = (char *)src;
	dest_cptr = (char *)dest;
	if (src_cptr == 0 && dest_cptr == 0)
		return (NULL);
	while (index < n)
	{
		dest_cptr[index] = src_cptr[index];
		index++;
	}
	return (dest_cptr);
}
