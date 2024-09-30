/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trgb.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:23:31 by spenning      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	trgb(int t, int r, int g, int b)
{
	if (t < 0 || t > 256)
		return (-1);
	if (r < 0 || r > 256)
		return (-1);
	if (g < 0 || g > 256)
		return (-1);
	if (b < 0 || b > 256)
		return (-1);
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
