/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstprint.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:56:22 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:42:24 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

void	lstprint(t_hittable *lst)
{
	t_hittable	*temp;

	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
	}
}

