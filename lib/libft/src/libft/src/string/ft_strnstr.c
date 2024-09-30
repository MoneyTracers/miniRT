/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/09 18:54:25 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:56:27 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// in this function we try to find little in string and pass the pointer
// to the first character of the first occurence of little in big.
// We first check if little is empty, and then we return big, if this
// is true. Then if we iterate through big for len amount of bytes. 
// If the length of little + index is bigger than length then we can already
// known that there is not enough space for little enough more in big for 
// the length that we are checking. Then if we find little with strncmp we
// return a pointer to the start of the first occurence. Otherwise we return
// Null if we don't find anything. 

#include "../../../../inc/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*l_cptr;
	char	*b_cptr;
	size_t	little_len;
	size_t	index;

	l_cptr = (char *)little;
	b_cptr = (char *)big;
	little_len = ft_strlen(l_cptr);
	index = 0;
	if (l_cptr[0] == '\0')
	{
		return (b_cptr);
	}
	while (b_cptr[index] != '\0' && index < len)
	{
		if ((little_len + index) > len)
			return (NULL);
		if (ft_strncmp(l_cptr, b_cptr + index, little_len) == 0)
			return (b_cptr + index);
		index++;
	}
	return (NULL);
}
