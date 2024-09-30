/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_welcome_lite.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:05:59 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 07:06:30 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printftests.h"
#include <stdio.h>

void	welcome_lite(void)
{
	printf(YEL "\nft_printf\n" RESET);
}

int	main(void)
{
	welcome_lite();
	return (0);
}
