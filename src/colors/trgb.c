/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trgb.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:51:26 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/27 12:51:30 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	create_trgb(float t, float r, float g, float b)
{
	int	red;
	int	green;
	int	blue;
	int	alpha;

	alpha = (int)t;
	red = (int)r;
	green = (int)g;
	blue = (int)b;
	return (alpha << 24 | red << 16 | green << 8 | blue);
}
