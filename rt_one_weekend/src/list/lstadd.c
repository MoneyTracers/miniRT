/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:31:33 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/15 13:52:05 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

int	lstadd(t_hittable **hittables, t_hittable *new_obj)
{
	t_hittable *new;

	new = lstnew(new_obj->type, &new_obj->center, new_obj->radius);
	if (new == NULL)
		return (1);
	lstadd_back(hittables, new);
	return (0);
}

