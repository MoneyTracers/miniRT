/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:36:05 by spenning          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:39 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this functoin creates a substring from s that starts at index start
// and is len bytes long. If the start is bigger or the same as the lenght
// of s, then it has to be an empty string, so a empty string is returned.
// if the len to too much longer than the substring that can be created from
// s + start, then the len is corrected to what cn be created. Afterwards
// the substring is created, copied, and null terminated 

#include "../../../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s_cptr;
	char	*ns_cptr;
	size_t	index;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	ns_cptr = (char *)ft_calloc(len + 1, 1);
	if (ns_cptr == NULL)
		return (NULL);
	s_cptr = (char *)s;
	index = 0;
	while (index < len && s_cptr[start] != '\0')
	{
		ns_cptr[index] = s_cptr[start];
		start++;
		index++;
	}
	ns_cptr[index] = '\0';
	return (ns_cptr);
}
