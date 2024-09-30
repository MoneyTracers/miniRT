/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/08 18:06:38 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:54:47 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

// this function takes parameter s and we try to find c witin
// n bytes. We first convert it to char pointer to be able to 
// compare byte by byte.
// unsigned char is added to make sure only characters are compared. 
// go off the ascii table. Otherwise it can never find the 
// char it is looking for in the memory. If chr is not found in
// n memory bytes then the pointer is made null and returned.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	index;
	char	*s_cptr;

	s_cptr = (char *)s;
	index = 0;
	while (index < n)
	{
		if ((unsigned char)s_cptr[index] == ((unsigned char)c))
		{
			s_cptr = s_cptr + index;
			return (s_cptr);
		}
		index++;
	}
	s_cptr = NULL;
	return (s_cptr);
}
