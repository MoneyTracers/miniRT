/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/06 20:08:25 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:53:02 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

// This function gets a pointer to a certain location together with 
// the buffer size it needs to set to zero. The void pointer given is
// typecasted to char * so each byte can be then set to 0 in the while loop
// we go until index < n because the index is set to 0 while n is total length
// and it not index based  

void	ft_bzero(void *s, size_t n)
{
	long unsigned int	index;
	char				*cptr;

	index = 0;
	cptr = (char *)s;
	while (index < n)
	{
		cptr[index] = '\0';
		index++;
	}
}
