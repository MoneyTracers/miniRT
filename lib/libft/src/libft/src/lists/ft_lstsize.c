/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:56:22 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:54:39 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*temp;

	size = 0;
	temp = malloc(sizeof(t_list));
	if (temp == NULL)
		return (0);
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	free(temp);
	return (size);
}
