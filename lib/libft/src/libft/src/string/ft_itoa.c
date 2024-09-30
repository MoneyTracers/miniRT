/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 17:23:57 by spenning          #+#    #+#             */
/*   Updated: 2024/05/14 21:00:55 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// this functions first makes a long integer to handle 
// int edge cases, then it counts the amount of memory it 
// needs to allocate with size_counter. if number is negative 
// then it will first put a '-'. afterwards it will go into the 
// recursive putnmbr function. it will end the function by null
// terminating the result. it takes into account the 0 edge case 
// by putting 0 + 48 and null terminating afterwards.

#include "../../../../inc/libft.h"

static void	putnmbr(char *string, long int numbers, int totalsize)
{
	if (numbers < 0)
		numbers = numbers * -1;
	if (numbers > 0)
	{
		putnmbr(string, numbers / 10, totalsize - 1);
		string[totalsize - 1] = 48 + (numbers % 10);
	}
}

static int	size_counter(long int ln)
{
	int	size;

	size = 0;
	if (ln < 0)
	{
		size++;
		ln = ln * -1;
	}
	while (ln > 9)
	{
		ln = ln / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	ln;
	int		count_size;
	char	*return_str;

	ln = n;
	count_size = size_counter(ln);
	count_size = count_size + 1;
	return_str = ft_calloc(sizeof(char), (count_size + 1));
	if (!return_str)
		return (NULL);
	if (n < 0)
		return_str[0] = '-';
	putnmbr(return_str, ln, count_size);
	if (n == 0)
		return_str[0] = 48 + 0;
	return_str[count_size] = '\0';
	return (return_str);
}
