/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lstdelone.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/23 13:44:39 by spenning      #+#    #+#                 */
/*   Updated: 2024/10/14 18:41:52 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <hittable.h>

void	lstdelone(t_hittable	*lst)
{
	free(lst);
	lst = NULL;
}
