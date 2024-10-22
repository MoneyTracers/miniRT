/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstadd.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:31:33 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/22 13:11:08 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	lstadd(t_hittable **hittables, t_hittable *new_obj)
{
	if (new_obj == NULL)
		return (1);
	lstadd_back(hittables, new_obj);
	return (0);
}

