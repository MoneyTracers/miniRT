/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd_back.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:31:33 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:37:37 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

void	lstadd_back(t_hittable	**lst, t_hittable	*new)
{
	t_hittable	*last;

	last = lstlast((*lst));
	if (last == NULL)
		(*lst) = new;
	else
		last->next = new;
}
