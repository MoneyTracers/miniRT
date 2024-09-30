/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/07 20:43:08 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:56:02 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

// This function gets the dst string, src string, and n bytes (full buffer) 
// it needs to concatenate at the end. the size it should copy is always 
// size - dst_len - 1. If size is not bigger than dst, it cannnot concat
// therefore it returns the length of the string it wanted to create
// if the copy size is bigger than src len than it automatically makes
// the copy size equal to the size of src_len to not run of the string
// then after checking if there is enough space in dst and the amount it 
// copies from src is the maximum it can copy the memory with memcpy and
// null terminate the end.

#include "../../../../inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	copy_size;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	copy_size = size - dst_len - 1;
	if (size <= dst_len)
		return (size + src_len);
	if (copy_size > src_len)
		copy_size = src_len;
	if (copy_size > 0)
	{
		ft_memcpy(dst + dst_len, src, copy_size);
		dst[dst_len + copy_size] = '\0';
	}
	return (dst_len + src_len);
}
