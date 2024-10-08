/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shade.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: spenning <spenning@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/07 13:23:31 by spenning      #+#    #+#                 */
/*   Updated: 2024/09/30 16:20:42 by spenning      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <rt.h>

int	add_shade(double distance, int trgb)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = 0;
	g = 0;
	b = 0;
	if (distance < 0 || distance > 1)
		return (-1);
	t = get_t(trgb) * (1 - distance);
	r = get_r(trgb) * (1 - distance);
	g = get_g(trgb) * (1 - distance);
	b = get_b(trgb) * (1 - distance);
	return (t << 24 | r << 16 | g << 8 | b);
}
