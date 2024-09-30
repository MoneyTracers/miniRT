/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:35:18 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:53:55 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

void	ft_lstadd_front(t_list	**lst, t_list	*new)
{
	new->next = (*lst);
	(*lst) = new;
}
