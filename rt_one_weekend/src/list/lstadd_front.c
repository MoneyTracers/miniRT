/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd_front.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:35:18 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:37:49 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

void	lstadd_front(t_hittable	**lst, t_hittable	*new)
{
	new->next = (*lst);
	(*lst) = new;
}
