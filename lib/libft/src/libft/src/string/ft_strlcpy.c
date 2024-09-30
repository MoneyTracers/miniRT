/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 22:35:47 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:56:06 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// strlcpy always returns the length of src. And it will keep on copying
// until it reaches size - 1, and there are still charachters to copy
// from src. Afterwards it null terminates the result.

#include "../../../../inc/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		srclen;
	size_t		index;

	srclen = ft_strlen(src);
	index = 0;
	if (size > 0)
	{
		while (index < (size -1) && src[index])
		{
			dst[index] = src[index];
			index ++;
		}
		dst[index] = '\0';
	}
	return (srclen);
}
