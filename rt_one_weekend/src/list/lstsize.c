/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstsize.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:56:22 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:42:43 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

int	lstsize(t_hittable *lst)
{
	int			size;
	t_hittable	*temp;

	size = 0;
	temp = lst;
	while (temp != NULL)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
