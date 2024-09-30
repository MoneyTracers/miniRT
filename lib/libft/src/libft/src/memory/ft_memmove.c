/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 22:35:47 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:55:04 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// In this function we want to move n bytes to dest from src.
// We want to watch out what the we do not remove the original
// source bytes when the src and dest are very close to each 
// other in memory. That's why we check dest_cptr < src_cptr,
// because if the dest is before src, you can copy to source 
// before it is copied over. If the dest is larger you coud 
// potentially copy over your source. 

#include "../../../../inc/libft.h"

static char	*reverse_move(char	*dest_cptr, char const	*src_cptr, size_t n)
{
	while (n > 0)
	{
		dest_cptr[n - 1] = src_cptr[n - 1];
		n--;
	}
	return (dest_cptr);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		index;
	const char	*src_cptr;
	char		*dest_cptr;

	dest_cptr = (char *)dest;
	src_cptr = (char *)src;
	index = 0;
	if (dest_cptr == 0 && src_cptr == 0)
		return (NULL);
	if (dest_cptr < src_cptr)
	{
		while (index < n)
		{
			dest_cptr[index] = src_cptr[index];
			index++;
		}
	}
	else
	{
		return (reverse_move(dest_cptr, src_cptr, n));
	}
	return (dest_cptr);
}
