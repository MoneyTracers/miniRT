/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstlast.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:46:33 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:42:04 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

t_hittable	*lstlast(t_hittable	*lst)
{
	t_hittable	*last;

	last = calloc(sizeof(t_hittable), 1);
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
