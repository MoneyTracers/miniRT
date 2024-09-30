/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdelone.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:44:39 by spenning      #+#    #+#                 */
/*   Updated: 2024/01/23 17:54:10 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../inc/libft.h"

void	ft_lstdelone(t_list	*lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}
