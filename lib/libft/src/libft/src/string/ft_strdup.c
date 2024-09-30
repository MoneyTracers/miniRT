/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 20:35:22 by spenning          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:03 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// returns copy of s with malloced ns_cptr
// if string is empty it will still return
// copy of empty string

#include "../../../../inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*s_cptr;
	size_t	s_len;
	void	*ns_vptr;
	char	*ns_cptr;
	size_t	index;

	s_cptr = (char *)s;
	s_len = ft_strlen(s_cptr);
	ns_vptr = ft_calloc(s_len + 1, 1);
	ns_cptr = (char *)ns_vptr;
	if (!ns_cptr)
		return (NULL);
	index = 0;
	while (s_cptr[index] != '\0')
	{
		ns_cptr[index] = s_cptr[index];
		index++;
	}
	ns_cptr[index] = '\0';
	return (ns_cptr);
}
