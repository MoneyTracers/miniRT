/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:31:02 by spenning          #+#    #+#             */
/*   Updated: 2024/05/14 21:01:14 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

// this functions frees all the already allocated indexs of the arrays
// if one of the allocations fails, so we don't have any lingering memory
// left. It starts from the 0 index until all the index that have been 
// allocated are freed. 

static int	free_all(char **allocation_array, size_t alc_index)
{
	size_t	index;

	index = 0;
	while (index <= alc_index)
	{
		free(allocation_array[index]);
		allocation_array[index] = 0;
		index++;
	}
	free(allocation_array);
	allocation_array = 0;
	return (0);
}
// this function detects a word by checking if the current index 
// is the delimiter or if the string has ended. In both cases it will 
// return the index to which it has incremented and the other functions
// in create splits deal with the rest. 

static size_t	get_token(char const *strin, char charact, size_t start_index)
{
	size_t	end_index;

	end_index = start_index;
	while (strin[end_index] != charact && strin[end_index] != '\0')
	{
		end_index++;
	}
	return (end_index);
}
// In this function we allocate the words to the appropriate index in the
// first dimension of the 2d array. We do this until all words are allocated
// we get the words by going through the whole string, and checking per 
// character if we have a word. This happends in the get token function
// This function returns the end index of where a words ends. If a word is 
// found then the end > start and we can store the word with ft_substring.
// If this fails then we free everything with free_all, otherwise we try to
// find the next word, or if we reached the end of the word we return the 
// array

static char	**create_splits(char **arr, char const *s, char ch, size_t spl)
{
	size_t	start;
	size_t	end;
	size_t	arr_index;

	start = 0;
	arr_index = 0;
	end = 0;
	while (arr_index < spl)
	{
		end = get_token(s, ch, start);
		if (end > start)
		{
			arr[arr_index] = ft_substr(s, start, end - start);
			if (arr[arr_index] == NULL)
			{
				free_all(arr, arr_index);
				return (NULL);
			}
			arr_index++;
		}
		if (!s[end])
			return (arr);
		start = end + 1;
	}
	return (arr);
}

// first we skip over all the delimiters, afterwards if the string
// is not done we add a count, then we skip over all the string that 
// is not a delimiter, until we hit either the end or we hit a 
// delimiter, then once we hit another charachter that is not delimiter
// and also not the end of the string we increment the count. This repeats
// until we find all the words or the end of the string.
static size_t	count_words(const char *str, char delim)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (str[index] != '\0' && str[index] == delim)
		index++;
	while (str[index] != '\0')
	{
		count++;
		while (str[index] != '\0' && str[index] != delim)
			index++;
		if (str[index] == '\0')
			break ;
		while (str[index] != '\0' && str[index] == delim)
			index++;
	}
	return (count);
}
// this the main function that first counts the amount of words we have
// then we allocate the amount of words + 1 for the null pointer to end the
// first dimension of the array. If this allocations falls we return null
// Then we go to create the splits, if this falls, we then return null
// in the end we null terminate the array and then return the 2d array

char	**ft_split(char const *s, char c)
{
	size_t	split_sum;
	char	**return_arr;

	split_sum = count_words(s, c);
	return_arr = (char **)ft_calloc(sizeof(char *), (split_sum + 1));
	if (return_arr == NULL)
		return (NULL);
	return_arr = create_splits(return_arr, s, c, (split_sum));
	if (return_arr == NULL)
		return (NULL);
	return_arr[split_sum] = NULL;
	return (return_arr);
}
