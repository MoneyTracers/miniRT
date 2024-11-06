/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maraasve <maraasve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:16:49 by maraasve          #+#    #+#             */
/*   Updated: 2024/11/06 13:59:46 by maraasve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>
#include <calculations.h>

float	ft_fabs(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

bool	equal_float(float a, float b)
{
	if (ft_fabs(a - b) > EPSILON)
		return (false);
	return (true);
}
