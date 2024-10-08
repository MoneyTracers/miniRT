/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   abs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mynodeus <mynodeus@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/21 10:41:30 by mynodeus      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	fdf_abs(int val)
{
	int	index;

	index = 0;
	if (val == 0)
		return (0);
	while (val < 0)
	{
		val++;
		index++;
	}
	while (val > 0)
	{
		val--;
		index++;
	}
	return (index);
}
