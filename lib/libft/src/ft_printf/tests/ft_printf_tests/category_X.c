/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category_X.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mynodeus <mynodeus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 07:59:26 by mynodeus          #+#    #+#             */
/*   Updated: 2024/05/17 08:17:31 by mynodeus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printftests.h"

void	category_cx(void)
{
	int	tc;

	tc = 1;
	printf(BMAG "%%X\n" RESET);
	tc = test_util(tc, "%X", 0);
	tc = test_util(tc, "%X", -10);
	tc = test_util(tc, "%X", -200000);
	tc = test_util(tc, "%X", -6000023);
	tc = test_util(tc, "%X", 10);
	tc = test_util(tc, "%X", 10000);
	tc = test_util(tc, "%X", 10000023);
	tc = test_util(tc, "%X", INT_MAX);
	tc = test_util(tc, "%X", INT_MIN);
	tc = test_util(tc, "dgs%Xxx", 10);
	tc = test_util(tc, "%X%Xd%X", 1, 2, -3);
	printf("\n");
	remove("ft_temp.txt");
	remove("temp.txt");
	freopen("/dev/tty", "w", stdout);
}
