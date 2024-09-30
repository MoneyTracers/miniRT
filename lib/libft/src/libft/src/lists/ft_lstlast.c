/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:46:33 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:54:22 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

t_list	*ft_lstlast(t_list	*lst)
{
	t_list	*last;

	last = malloc(sizeof(t_list));
	if (last == NULL)
		return (NULL);
	last = lst;
	if (last == NULL)
		return (NULL);
	if (last->next == NULL)
		return (last);
	while (last != NULL)
	{
		if (last->next->next == NULL)
		{
			last = last->next;
			return (last);
		}
		last = last->next;
	}
	return (last);
}
