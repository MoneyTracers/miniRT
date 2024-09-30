/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spenning <spenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:33:02 by spenning          #+#    #+#             */
/*   Updated: 2024/05/14 20:59:04 by spenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

void	free_char_array(char **arr)
{
	int	index;

	index = 0;
	while (arr[index] != NULL)
	{
		free(arr[index]);
		arr[index] = 0;
		index++;
	}
	free(arr);
	arr = NULL;
}
