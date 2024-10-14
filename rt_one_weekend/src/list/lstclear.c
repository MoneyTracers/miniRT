/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstclear.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:43:12 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:41:29 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

void	lstclear(t_hittable	**lst)
{
	t_hittable	*temp_frt;
	t_hittable	*temp_bck;

	if (!lst)
		return ;
	temp_frt = (*lst);
	temp_bck = (*lst);
	while (temp_bck)
	{
		temp_frt = temp_frt->next;
		free(temp_bck);
		temp_bck = temp_frt;
	}
	(*lst) = 0;
}
