/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:38:41 by spenning          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:49 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// function tries to trim certain set from the beginning with
// is trimmable. Then it goes to the end to do the same. 
// If all is trimmed then a string is malloced, and it is returned
// if successfull. 

#include "../../../../inc/libft.h"

static int	istrimmable(char const *s1, char const *set)
{
	char	*set_cptr;
	char	*s1_cptr;

	set_cptr = (char *)set;
	s1_cptr = (char *)s1;
	while ((set_cptr[0] != '\0') && (s1_cptr[0] != '\0'))
	{
		if (s1_cptr[0] == set_cptr[0])
		{
			return (1);
		}
		set_cptr++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	remainder;
	char	*s1_cptr;
	char	*s_return;

	s1_cptr = (char *)s1;
	s_return = 0;
	while (istrimmable(s1_cptr, set))
	{
		s1_cptr++;
	}
	remainder = ft_strlen(s1_cptr);
	while (istrimmable((s1_cptr + remainder) - 1, set) && remainder > 0)
	{
		remainder--;
	}
	remainder = remainder + 1;
	s_return = (char *)ft_calloc(remainder, 1);
	if (s_return == NULL)
		return (NULL);
	ft_strlcpy(s_return, s1_cptr, remainder);
	return (s_return);
}
